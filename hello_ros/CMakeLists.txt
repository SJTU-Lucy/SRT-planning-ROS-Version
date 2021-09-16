cmake_minimum_required(VERSION 2.8.3)
# 程序的名字
project(hello_ros)
# 使用的内置包，这里用到了roscpp
find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
  std_msgs
  dynamic_reconfigure
)

## Generate messages in the 'msg' folder
add_message_files(
   FILES
   test.msg
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

generate_dynamic_reconfigure_options(
  config/dynamic.cfg
)

# 链接本地库
# INCLUDE_DIRS - 声明给其它package的include路径
# LIBRARIES - 声明给其它package的库
# CATKIN_DEPENDS - 本包依赖的catkin package
# DEPENDS - 本包依赖的非catkin package
# CFG_EXTRAS - 其它配置参数
catkin_package(
   INCLUDE_DIRS include 
   CATKIN_DEPENDS message_runtime std_msgs roscpp dynamic_reconfigure
)

catkin_package(
  LIBRARIES custom_dynamic_reconfigure
  CATKIN_DEPENDS roscpp std_msgs dynamic_reconfigure
)

# 头文件位置，一般不需要改动，就是include
include_directories( include ${catkin_INCLUDE_DIRS})

# 生成静态库
add_library(Header
    include/hello_ros/header.h
    src/header.cpp
)
add_dependencies(Header ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(Header ${catkin_LIBRARIES})


# 生成可执行文件，将src/hello.cpp生成可执行文件hello
add_executable(hello src/hello.cpp)
target_link_libraries(hello Header ${catkin_LIBRARIES})

add_executable(talker src/talker.cpp)
target_link_libraries(talker Header ${catkin_LIBRARIES})

add_executable(listener src/listener.cpp)
target_link_libraries(listener Header ${catkin_LIBRARIES})

# make sure configure headers are built before any node using them
add_executable(dynamic_reconfigure_node src/server.cpp)
# make sure configure headers are built before any node using them
add_dependencies(dynamic_reconfigure_node ${PROJECT_NAME}_gencfg)
# for dynamic reconfigure
target_link_libraries(dynamic_reconfigure_node ${catkin_LIBRARIES})

