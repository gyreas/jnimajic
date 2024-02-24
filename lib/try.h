#include "jni.h"
#include "jni_md.h"

#ifndef _Included_Try
#define _Included_Try

#ifdef  __cplusplus
extern "C" {
#endif // __cplusplus
	/*
	 * Class: Try
	 * Method: hello
	 * Signature: ()V
	 */
	JNIEXPORT void JNICALL Java_Try_hello
	(JNIEnv *, jobject);

	/*
	 * Class: Try
	 * Method: arr
	 * Signature: ()[Ljava/lang/String;
	 */
	JNIEXPORT jobjectArray JNICALL Java_Try_arr
	(JNIEnv *, jobject);
	/*
	 * Class: Try
	 * Method: arr
	 * Signature: ()[Ljava/lang/String;
	 */
	JNIEXPORT jobjectArray JNICALL Java_Try_cpair_from_array
	(JNIEnv *env, jobject ptr_obj, jobjectArray jarr);

	/*
	 * Class: Try
	 * Method: cpair_from_array
	 * Signature: ([Ljava/lang/String;)[Laadesaed/try/CPair;
	 */
	JNIEXPORT jobjectArray JNICALL Java_Try_cpairFromArray
	(JNIEnv *env, jobject this, jarray jarr);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // _Included_Try
