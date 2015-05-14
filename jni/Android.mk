LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := base64
LOCAL_SRC_FILES := base64.cpp
LOCAL_SRC_FILES += base64Impl.cpp
include $(BUILD_SHARED_LIBRARY)
