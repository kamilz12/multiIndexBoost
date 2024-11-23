cmake_minimum_required(VERSION 3.29)
project(lab6_domowe)

set(CMAKE_CXX_STANDARD 20)
set(BOOST_ROOT "C:/boost_1_86_0")
set(BOOSTROOT "C:/boost_1_86_0")
find_package(Boost 1.86.0)
set(Boost_INCLUDE_DIR C:/boost_1_86_0/)
set(Boost_LIBRARY_DIR C:/boost_1_86_0/stage/lib)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})
set(CMAKE_CXX_STANDARD 20)

add_executable(lab6_domowe main.cpp
        Contact.h
        Contacts.h
        Contact.cpp
        Contacts.cpp)
