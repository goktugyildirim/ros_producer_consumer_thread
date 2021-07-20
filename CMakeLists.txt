cmake_minimum_required(VERSION 3.5)
project(producer_consumer)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -O3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g -O3")

find_package(catkin REQUIRED COMPONENTS
        roscpp
        std_msgs
        )

find_package( Boost )

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
)

add_executable(producer_consumer
        src/main.cpp
        src/producer_consumer_node.cpp
        src/consumer.cpp
        )

add_dependencies(producer_consumer
        ${catkin_EXPORTED_TARGETS}
        )

target_link_libraries(producer_consumer
        ${Boost_LIBRARIES}
        ${catkin_LIBRARIES}
        )




