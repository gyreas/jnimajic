#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/try.h"

// TODO: Return modification
/* void map(void *base, size_t count, void *fn) { */
/* 	for (size_t i = 0; i < count; i++) { */
/* 		void *elem = base[i]; */
/* 		*elem = (fn)(elem); */
/* 	} */
/* } */

JNIEXPORT void JNICALL Java_Try_hello(JNIEnv *env, jobject this)
{
	printf("hello bitch\n");
}

JNIEXPORT jobjectArray JNICALL Java_Try_arr(JNIEnv *env, jobject this)
{
	jint sz = 3;

	jclass class = (*env)->FindClass(env, "Ljava/lang/String;");
	if (!class) {
		fprintf(stderr, "Could not find class.\n");
		exit(EXIT_FAILURE);
	}

	jobjectArray oa = (*env)->NewObjectArray(env, sz, class, NULL);
	if (!oa) {
		fprintf(stderr, "Could not create array.\n");
		exit(EXIT_FAILURE);
	}

	char *hello[] = {"Oh", "mya", "god"};

	for (int i = 0; i < sz; i++) {
		const char *str = hello[i];
		jstring jstr = (*env)->NewStringUTF(env, str);
		if (!jstr) {
			fprintf(stderr, "Could not create string.\n");
			exit(EXIT_FAILURE);
		}
		(*env)->SetObjectArrayElement(env, oa, i, jstr);
	}
	return oa;
}

JNIEXPORT jobjectArray JNICALL Java_Try_cpairFromArray(JNIEnv *env, jobject this, jarray jarr) {
	size_t len = (*env)->GetArrayLength(env, jarr);

	jclass class =(*env)->FindClass(env, "CPair");
	if (!class) {
		fprintf(stderr, "Could not find class\n");
		exit(EXIT_FAILURE);
	}
	
	jobject init = NULL;
	jobjectArray jarr_cpair = (*env)->NewObjectArray(env, len, class, init);
	if (!jarr_cpair) {
		fprintf(stderr, "Could not create array.\n");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < len; i++) {
		jstring jstr = (*env)->GetObjectArrayElement(env, jarr, i);
		if (!jstr) {
			fprintf(stderr, "Could not get object array element.\n");
			exit(EXIT_FAILURE);
		}

		size_t str_len = (*env)->GetStringLength(env, jstr);
		if (!str_len) {
			fprintf(stderr, "Could not get string lenght.\n");
			exit(EXIT_FAILURE);
		};

		jmethodID m_ID = (*env)->GetMethodID(env, class, "<init>", "(Ljava/lang/String;I)V");
		if (!m_ID) {
			fprintf(stderr, "Could not get method ID.\n");
			exit(EXIT_FAILURE);
		}

		jvalue values[2];
		values[0].l = jstr;
		values[1].i = str_len;
		
		jobject cpair = (*env)->NewObjectA(env, class, m_ID, values);
		if (!cpair) {
			fprintf(stderr, "Could not create pair.\n");
			exit(EXIT_FAILURE);
		}

		(*env)->SetObjectArrayElement(env, jarr_cpair, i, cpair);
	}

	return jarr_cpair;
}
