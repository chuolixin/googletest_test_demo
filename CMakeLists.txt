#表示cmake的最低版本要求是2.8
cmake_minimum_required (VERSION 2.8)

#表示cmake工程信息，也就是工程名叫demo
project (demo)

#表示最终要生成的elf文件的名字叫main，使用的源文件是main.c
add_executable(main main.c)

#把当前目录下的源文件存列表存放到变量SRC_LIST里，然后在add_executable里调用SRC_LIST。
aux_source_directory(. SRC_LIST)
add_executable(main ${SRC_LIST})

#aux_source_directory()也存在弊端，它会把指定目录下的所有源文件都加进来，
#可能会加入一些我们不需要的文件，此时我们可以使用set命令去新建变量来存放需要的源文件
set( SRC_LIST
	 ./main.c
	 ./testFunc1.c
	 ./testFunc.c)
add_executable(main ${SRC_LIST})

#include_directories。该命令是用来向工程添加多个指定头文件的搜索路径，路径之间用空格分隔。test_func test_func1是两个文件夹
#test_func test_func1 存放到变量SRC_LIST里
include_directories (test_func test_func1)
aux_source_directory (test_func SRC_LIST)
aux_source_directory (test_func1 SRC_LIST1)
add_executable (main main.c ${SRC_LIST} ${SRC_LIST1})

#add_subdirectory()，这个命令可以向当前工程添加存放源文件的子目录
add_subdirectory (src)#根目录

#命令set，是用于定义变量的
#EXECUTABLE_OUTPUT_PATH ：目标二进制可执行文件的存放位置
#PROJECT_SOURCE_DIR：工程的根目
aux_source_directory (. SRC_LIST)#SRC目录
include_directories (../include)
add_executable (main ${SRC_LIST})
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#############################################################
aux_source_directory (src SRC_LIST)
include_directories (include)
add_executable (main ${SRC_LIST})
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#add_library: 生成动态库或静态库(第1个参数指定库的名字；第2个参数决定是动态还是静态，如果没有就默认静态；第3个参数指定生成库的源文件)
#set_target_properties: 设置最终生成的库的名称，还有其它功能，如设置库的版本号等等
#LIBRARY_OUTPUT_PATH: 库文件的默认输出路径，这里设置为工程目录下的lib目录
set (SRC_LIST ${PROJECT_SOURCE_DIR}/testFunc/testFunc.c)
add_library (testFunc_shared SHARED ${SRC_LIST})
add_library (testFunc_static STATIC ${SRC_LIST})
set_target_properties (testFunc_shared PROPERTIES OUTPUT_NAME "testFunc")
set_target_properties (testFunc_static PROPERTIES OUTPUT_NAME "testFunc")
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#find_library: 在指定目录下查找指定库，并把库的绝对路径存放到变量里，其第一个参数是变量名称，第二个参数是库名称，第三个参数是HINTS，第4个参数是路径
#target_link_libraries: 把目标文件与库文件进行链接
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set (SRC_LIST ${PROJECT_SOURCE_DIR}/src/main.c)
include_directories (${PROJECT_SOURCE_DIR}/testFunc/inc)
find_library(TESTFUNC_LIB testFunc.a HINTS ${PROJECT_SOURCE_DIR}/testFunc/lib)
add_executable (main ${SRC_LIST})
target_link_libraries (main ${TESTFUNC_LIB})



