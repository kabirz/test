LOCAL_PATH := $(call my-dir)  
include $(CLEAR_VARS)  
  
LOCAL_SRC_FILES := ThreadTest.cpp  
     
LOCAL_SHARED_LIBRARIES :=libcutils \  
    libutils    
      
LOCAL_MODULE := test

LOCAL_MODULE_PATH := /home/tool
LOCAL_MODULE_TAGS := eng  
      
LOCAL_PRELINK_MODULE := false  
  
include $(BUILD_EXECUTABLE)
