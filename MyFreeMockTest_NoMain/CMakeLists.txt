#最小版本
cmake_minimum_required(VERSION 3.5)

#工程名字
project(demo)

#把当前文件下的所有文件放到SRC_LIS  
aux_source_directory(. SRC_LIST)
aux_source_directory(./stub SRC_LIST1)
#set(SRC_LIST ./test_gtest.cpp)
#set(SRC_LIST ./test_gmock.cpp)
#包含头文件
include_directories(include)
include_directories(./stub)

#找gtest库
find_library(GTEST_LIB libgtest.a HINTS ${PROJECT_SOURCE_DIR}/lib)

#找gmock库
find_library(GMOCK_LIB libgmock.a HINTS ${PROJECT_SOURCE_DIR}/lib)

#找gmock_main库
find_library(GMOCKMAIN_LIB libgmock_main.a HINTS ${PROJECT_SOURCE_DIR}/lib)

#找pthread库
find_package(Threads)

#add_compile_options(-std=c++11)

#set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS "-pthread" LINK_FLAGS "-pthread")

#编译
add_executable(main ${SRC_LIST} ${SRC_LIST1})

#链接
target_link_libraries(main ${GTEST_LIB} ${GMOCK_LIB} ${CMAKE_THREAD_LIBS_INIT} ${GMOCKMAIN_LIB})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O -g3")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs")




