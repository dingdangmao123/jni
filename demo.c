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
  	jobject obj;

  	jfieldID jid1;

  	jfieldID jid2;

  	jstring js;


  	jclass clz=(*env)->FindClass(env,"demo");

  	mid=(*env)->GetMethodID(env,clz,"<init>","()V");

  	obj=(*env)->NewObject(env,clz,mid);
  	

  	jid1=(*env)->GetFieldID(env,clz,"num","I");
  	(*env)->SetIntField(env,obj,jid1,100);


  	jid2=(*env)->GetFieldID(env,clz,"str","Ljava/lang/String;");
  	(*env)->SetIntField(env,obj,jid1,100);
  	js=(*env)->NewStringUTF(env,"hello jni string");
  	(*env)->SetObjectField(env,obj,jid2,js);


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

  }