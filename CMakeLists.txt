cmake_minimum_required(VERSION 3.20)
project(curs)

set(CMAKE_CXX_STANDARD 17)

add_executable(curs main.cpp Transport.h Transport.cpp Vehicle.h Vehicle.cpp Motorcycle.h Motorcycle.cpp Truck.h Truck.cpp Bus.h Bus.cpp)
