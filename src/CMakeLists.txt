CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)
SET(CMAKE_LEGACY_CYGWIN_WIN32 0)

PROJECT(DistributeShell)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb ")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
SET(CMAKE_BUILD_TYPE Debug)


LINK_DIRECTORIES(/usr/local/lib)


#include third lib_src
#set the middle lib output path
ADD_SUBDIRECTORY(yarn_client ../lib)
ADD_SUBDIRECTORY(test)
#source setting
AUX_SOURCE_DIRECTORY(. SRC)
ADD_EXECUTABLE(distribute_shell ${SRC})

TARGET_LINK_LIBRARIES(distribute_shell yarnclient)
SET_TARGET_PROPERTIES(distribute_shell PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ../bin)
