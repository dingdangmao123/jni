#include "demo.h"
#include <stdio.h>

/*
 * Class:     demo
 * Method:    createdemo
 * Signature: ()Ldemo;
 */
JNIEXPORT jobject JNICALL Java_demo_createdemo
  (JNIEnv * env, jclass clazz){

  	jmethodID mid;

  	jmethodID mid2;

  	jobject obj;

  	jfieldID jid1;

  	jfieldID jid2;

  	jstring js;


  	jclass clz=(*env)->FindClass(env,"demo");

  	mid=(*env)->GetMethodID(env,clz,"<init>","()V");
  	mid2=(*env)->GetMethodID(env,clz,"jnishow","()V");

  	obj=(*env)->NewObject(env,clz,mid);
  	

  	jid1=(*env)->GetFieldID(env,clz,"num","I");
  	(*env)->SetIntField(env,obj,jid1,100);


  	jid2=(*env)->GetFieldID(env,clz,"str","Ljava/lang/String;");
  	(*env)->SetIntField(env,obj,jid1,100);
  	js=(*env)->NewStringUTF(env,"hello jni string");
  	(*env)->SetObjectField(env,obj,jid2,js);

  	(*env)->CallVoidMethod(env,obj,mid2);

  	return obj;


  }

/*
 * Class:     demo
 * Method:    show
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_demo_show
  (JNIEnv * env, jobject obj){

  	jint ji;
  	jstring js;
	jfieldID jid1;
	jfieldID jid2;
	jclass clz;
	const char * str=NULL;
	clz=(*env)->FindClass(env,"demo");


  	jid1=(*env)->GetFieldID(env,clz,"num","I");
  	jid2=(*env)->GetFieldID(env,clz,"str","Ljava/lang/String;");


  	ji=(*env)->GetIntField(env,obj,jid1);
  	js=(*env)->GetObjectField(env,obj,jid2);
  	str=(*env)->GetStringUTFChars(env,js,0);


  	printf("jni_show num:%d str:%s\n",ji,str);
  	(*env)->ReleaseStringUTFChars(env,js,str);

  	printf("----------------\n");

  }


/*
 * Class:     demo
 * Method:    get
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_demo_get
  (JNIEnv * env, jobject obj){

/*
   jstring (JNICALL *NewStringUTF)
      (JNIEnv *env, const char *utf);

    jobjectArray (JNICALL *NewObjectArray)
      (JNIEnv *env, jsize len, jclass clazz, jobject init);
    jobject (JNICALL *GetObjectArrayElement)
      (JNIEnv *env, jobjectArray array, jsize index);
    void (JNICALL *SetObjectArrayElement)
      (JNIEnv *env, jobjectArray array, jsize index, jobject val);

    jclass (JNICALL *GetObjectClass)
      (JNIEnv *env, jobject obj);

*/
  	jsize len=3;
  	jsize i=0;
  	char *p[3]={"Android","iOS","WP"};
  	jstring js=(*env)->NewStringUTF(env,"init");

  	jclass clz=(*env)->GetObjectClass(env,js);
  	

	jobjectArray ja=(*env)->NewObjectArray(env,3,clz,js);


	for(i=0;i<len;i++){
		(*env)->SetObjectArrayElement(env,ja,i,(*env)->NewStringUTF(env,p[i]));
	}
	

	return ja;
  }


/*
 * Class:     demo
 * Method:    Array
 * Signature: ([Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_demo_Array
  (JNIEnv * env, jobject obj, jobjectArray ja){
  	jstring js;
  	const char* str=NULL;
  	jsize len=(*env)->GetArrayLength(env,ja);
  	jint i=0;
  	for(i=0;i<len;i++){

  		js=(*env)->GetObjectArrayElement(env,ja,i);
  		str=(*env)->GetStringUTFChars(env,js,0);
 		printf("jni %s\n",str);
  		(*env)->ReleaseStringUTFChars(env,js,str);

  	}

  	printf("----------------\n");

  }