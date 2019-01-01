#include <jni.h>
#include <stdlib.h>
#include <android/log.h>

#define LOG_TAG "wangweijun"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

JNIEXPORT jstring JNICALL Java_com_example_wangweijun_jni_1test_HelloWorld_helloWorld
        (JNIEnv *env, jclass jobj) {
    LOGD("hello from jni ");
    char *str = "hello jni";
    return (*env)->NewStringUTF(env, str);
}

JNIEXPORT jint JNICALL Java_com_example_wangweijun_jni_1test_HelloWorld_addStaticMethod
        (JNIEnv *env, jclass jClazz, jint x, jint y) {
    return x + y;
}

/*
 * Class:     com_example_wangweijun_jni_test_HelloWorld
 * Method:    add
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_example_wangweijun_jni_1test_HelloWorld_add
        (JNIEnv *env, jobject thiz, jint x, jint y) {
    return x + y;
}

JNIEXPORT jintArray JNICALL Java_com_example_wangweijun_jni_1test_HelloWorld_arrElementsIncrease
        (JNIEnv *env, jobject thiz, jintArray jarr) {
    LOGD("arrElementsIncrease");
    int size = (*env)->GetArrayLength(env, jarr);
    LOGD("size = %d", size);
    int* p = (*env)->GetIntArrayElements(env, jarr, NULL);
    int i;
    for (i = 0; i < size; i++) {
        *(p+i) += 10;
        LOGD("i = %d", *(p+i));
    }
    return jarr;
}

/*
 * Class:     com_example_wangweijun_jni_test_HelloWorld
 * Method:    sayHelloInc
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_wangweijun_jni_1test_HelloWorld_sayHelloInc
        (JNIEnv *env, jobject thiz, jstring jstr) {
//    char* cstr = _JString2CStr(env, jstr);

    char* cstr = (*env)->GetStringUTFChars(env, jstr,NULL);
    int length = strlen(cstr);
    int i=0;
    for (int i = 0; i < length ; ++i) {
        *(cstr+i) = *(cstr+i) + 1;
    }
    return (*env)->NewStringUTF(env, cstr);
    return NULL;
}

//char *_JString2CStr(JNIEnv *env, jstring jstr) {
//    char *rtn = NULL;
//    jclass classtring = (*env)->FindClass(env, "java/lang/String");
//    jstring strencode = (*env)->NewStringUTF(env, "GB2312");
//    jmethodID mid = (*env)->GetMethodID(env, classtring, "getBytes", "(Ljava/lang/String;)[B");
//    jbyteArray barr = (jbyteArray) (*env)->CallObjectMethod(env, jstr, mid,
//                                                            strencode);// String.getBytes("GB2312");
//    jsize alen = (*env)->GetArrayLength(env, barr);
//    jbyte *ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
//    if (alen > 0) {
//        rtn = (char*)malloc(alen + 1);
//        memcpy(rtn, ba, alen);
//        rtn[alen] = 0;
//    }
//    (*env)->ReleaseByteArrayElements(env, barr, ba, 0);
//    return rtn;
//}



char* _JString2CStr(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass classtring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env, "GB2312");
    jmethodID mid = (*env)->GetMethodID(env, classtring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) (*env)->CallObjectMethod(env, jstr, mid,
                                                            strencode);// String.getBytes("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char*)malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba, 0);
    return rtn;
}


JNIEXPORT jstring JNICALL Java_com_example_wangweijun_jni_1test_HelloWorld_strAppend(
        JNIEnv *env, jobject obj, jstring contentStr) {
    //获取字符串指针，必须使用指针，不能使用char strContent[],因为GetStringUTFChars()返回值为const char *;
    const char *strContent = (*env)->GetStringUTFChars(env, contentStr, JNI_FALSE);
    char str[] = "欢迎你的到来！";
    //字符串拼接,实现strContent+str1,因为strcat的第一个参数必须为非const类型(可变)，
            // 所以不能直接使用strcat()
    //创建一个新的字符串指针
    char *strTemp = (char *) malloc(strlen(strContent) + strlen(str) + 1);
    //拷贝常量到字符串指针
    strcpy(strTemp, strContent);
    //拼接str1到strTemp
    strcat(strTemp, str);
    //返回一个utf的jstring
    return (*env)->NewStringUTF(env, strTemp);
}


