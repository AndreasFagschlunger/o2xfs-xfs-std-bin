/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class at_o2xfs_xfs_std_StdXfsApi */

#ifndef _Included_at_o2xfs_xfs_std_StdXfsApi
#define _Included_at_o2xfs_xfs_std_StdXfsApi
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    loadLibrary0
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_loadLibrary0
  (JNIEnv *, jobject);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfmSetTraceLevel
 * Signature: ([B[B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfmSetTraceLevel
  (JNIEnv *, jobject, jbyteArray, jbyteArray);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsAsyncClose
 * Signature: ([B[B[B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncClose
  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsAsyncDeregister
 * Signature: ([B[B[B[B[B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncDeregister
  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsAsyncExecute
 * Signature: ([B[B[B[B[B[B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncExecute
  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsAsyncGetInfo
 * Signature: ([B[B[B[B[B[B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncGetInfo
  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsAsyncLock
 * Signature: ([B[B[B[B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncLock
  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray, jbyteArray);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsAsyncOpen
 * Signature: ([B[B[B[B[B[B[B[B[B[B[B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncOpen
  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsAsyncRegister
 * Signature: ([B[B[B[B[B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncRegister
  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray, jbyteArray, jbyteArray);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsAsyncUnlock
 * Signature: ([B[B[B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncUnlock
  (JNIEnv *, jobject, jbyteArray, jbyteArray, jbyteArray);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsCancelAsyncRequest
 * Signature: ([B[B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsCancelAsyncRequest
  (JNIEnv *, jobject, jbyteArray, jbyteArray);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsCleanUp
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsCleanUp
  (JNIEnv *, jobject);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsCreateAppHandle
 * Signature: ([B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsCreateAppHandle
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsDestroyAppHandle
 * Signature: ([B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsDestroyAppHandle
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsFreeResult
 * Signature: ([B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsFreeResult
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsIsBlocking
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsIsBlocking
  (JNIEnv *, jobject);

/*
 * Class:     at_o2xfs_xfs_std_StdXfsApi
 * Method:    wfsStartUp
 * Signature: ([B[B)I
 */
JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsStartUp
  (JNIEnv *, jobject, jbyteArray, jbyteArray);

#ifdef __cplusplus
}
#endif
#endif