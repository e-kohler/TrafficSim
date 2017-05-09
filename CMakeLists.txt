cmake_minimum_required(VERSION 3.7)
project(TrafficSim)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        structures/array_list.h
        structures/array_queue.h
        structures/array_stack.h
        structures/circular_list.h
        structures/doubly_circular_list.h
        structures/doubly_linked_list.h
        structures/linked_list.h
        structures/linked_queue.h
        structures/linked_stack.h
        TrafficSim/event.cpp
        TrafficSim/event.h
        TrafficSim/main.cpp
        TrafficSim/road.cpp
        TrafficSim/road.h
        TrafficSim/semaphore.cpp
        TrafficSim/semaphore.h
        TrafficSim/vehicle.cpp
        TrafficSim/vehicle.h)

add_executable(TrafficSim ${SOURCE_FILES})