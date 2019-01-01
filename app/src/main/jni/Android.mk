LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := hello_jni
LOCAL_SRC_FILES =: hello_jni.c
LOCAL_LDLIBS += -llog

APP_ABI := all
include $(BUILD_SHARED_LIBRARY)