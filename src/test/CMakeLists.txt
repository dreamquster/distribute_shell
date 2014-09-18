cmake_minimum_required(VERSION 2.8.4)
#set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required
project(UnitTest CXX)
SET(CMAKE_BULID_TYPE Debug)
INCLUDE_DIRECTORIES(../yarn_client)
LINK_DIRECTORIES(/usr/local/lib ../lib)

FILE(GLOB_RECURSE SRC_LIST "*.cpp" "*.cc")
ADD_EXECUTABLE(UnitTest ${SRC_LIST})
TARGET_LINK_LIBRARIES(UnitTest gtest log4cplus pthread yarnclient)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../bin)