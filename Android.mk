LOCAL_PATH := $(call my-dir)

# libhelloworldservice shared library

include $(CLEAR_VARS)

LOCAL_MODULE := libhelloworldservice

LOCAL_SRC_FILES := \
	IHelloWorldService.cpp

LOCAL_SHARED_LIBRARIES := \
	libbinder \
	libutils

include $(BUILD_SHARED_LIBRARY)

# helloworldservice executable

include $(CLEAR_VARS)

LOCAL_MODULE := helloworldservice

LOCAL_SRC_FILES := \
	HelloWorldService.cpp

LOCAL_SHARED_LIBRARIES := \
	libbinder \
	libutils \
	libhelloworldservice

include $(BUILD_EXECUTABLE)

# helloworldclient executable

include $(CLEAR_VARS)

LOCAL_MODULE := helloworldclient

LOCAL_SRC_FILES := \
	HelloWorldClient.cpp

LOCAL_SHARED_LIBRARIES := \
	libbinder \
	libutils \
	libhelloworldservice

include $(BUILD_EXECUTABLE)
