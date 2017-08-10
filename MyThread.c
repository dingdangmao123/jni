#include "MyThread.h"
#include <pthread.h>
#include <stdlib.h>
JavaVM * jvm;

void * Worker(void * arg);

jint * data;
pthread_t * handles;

jint JNI_OnLoad(JavaVM *vm, void * p){

	jvm=vm;
	return JNI_VERSION_1_4;
}




/*
 * Class:     pthread
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_MyThread_init
  (JNIEnv *env, jclass clz){

  	printf("init\n");

  }

/*
 * Class:     pthread
 * Method:    start
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_MyThread_start
  (JNIEnv *env, jclass clz,jint num,jint every){
  	jclass exp;
  	jint i=0;
  	data=(jint*)malloc(sizeof(jint)*num);

  	handles=(pthread_t*)malloc(sizeof(pthread_t)*num);

  	if(data==NULL||handles==NULL){

  		exp=(*env)->FindClass(env,"java/lang/RuntimeException");

  		(*env)->ThrowNew(env,clz,"malloc failure!");

  	}
	for(i=0;i<num;i++){
		data[i]=every;
   // printf("%d\n",data[i]);
		pthread_create(handles+i,NULL,Worker,data+i);
	}


  }

/*
 * Class:     pthread
 * Method:    free
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_MyThread_free
  (JNIEnv *env , jclass clz){

  	free(data);

  	free(handles);

  }

 void * Worker(void * arg){

 		jint id=(jint*)arg-data;

 		jint num=data[id];
   // printf("%d\n",num);

 		jint i=0;
   // num=2;
 		for(i=0;i<num;i++){

 			printf("id->%d %d\n",id+1,i);

 		}

  }