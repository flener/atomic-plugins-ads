LOCAL_PATH := $(call my-dir)
APP_STL=c++_shared

APP_PLATFORM := android-9


include $(CLEAR_VARS)
LOCAL_SRC_FILES := \
	$(LOCAL_PATH)/AdServiceAndroid.cpp

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/../../ \
    $(LOCAL_PATH)/safejni/
LOCAL_CPPFLAGS := \
	-frtti \
	-fexceptions \
	-std=c++11 \
	-D__GXX_EXPERIMENTAL_CXX0X__
LOCAL_MODULE := AdService
include $(BUILD_STATIC_LIBRARY)
