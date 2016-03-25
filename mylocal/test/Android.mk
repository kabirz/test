# Copyright 2005 The Android Open Source Project

TOP = /mtk/new/Y36/
LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	zhp.c


LOCAL_MODULE:= main

LOCAL_MODULE_PATH :=/tmp

include $(BUILD_HOST_EXECUTABLE)
