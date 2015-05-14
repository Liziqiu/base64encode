#include <jni.h>
#include <stdio.h>
#include <string.h>
#include "base64.h"
#include  "base64Impl.h"
/*
 * Class:     com_gdut_base64_base64
 * Method:    base64encode
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_gdut_base64_base64_base64encode
  (JNIEnv* env, jobject obj, jstring str){
	    const char* strs;
		strs = (env)->GetStringUTFChars(str,NULL);
		char* str2=base64encode(strs);
		env->ReleaseStringUTFChars(str,strs);
		jstring result = (env)->NewStringUTF(str2);
		free(str2);
		return result;
}

/*
 * Class:     com_gdut_base64_base64
 * Method:    base64decode
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_gdut_base64_base64_base64decode
  (JNIEnv* env, jobject obj, jstring str){
	    const char* strs;
		strs = (env)->GetStringUTFChars(str,NULL);
		char* str2=base64decode(strs);
		env->ReleaseStringUTFChars(str,strs);
		jstring result = (env)->NewStringUTF(str2);
		free(str2);
		return result;
}
