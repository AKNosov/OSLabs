project(control)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)
pkg_check_modules(PC_ZeroMQ QUIET zmq)

find_path(ZeroMQ_INCLUDE_DIR
        NAMES zmq.hpp
        PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
        )

find_library(ZeroMQ_LIBRARY
        NAMES zmq
        PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
        )


add_executable(control control.cpp)
add_executable(calc calc.cpp)


target_include_directories(control PUBLIC ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(control PUBLIC ${ZeroMQ_LIBRARY})
target_include_directories(calc PUBLIC ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(calc PUBLIC ${ZeroMQ_LIBRARY})