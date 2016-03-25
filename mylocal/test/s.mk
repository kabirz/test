LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES := a.c
LOCAL_MODULE := main
LOCAL_MODULE_PATH :=/zhp/test

include $(BUILD_HOST_EXECUTABLE)
