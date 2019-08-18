cmake_minimum_required(VERSION 3.14)
project(QuickBpmTapper)

FILE(GLOB cmakes ${CMAKE_SOURCE_DIR}/cmake/*.cmake)
FOREACH (cmake ${cmakes})
    INCLUDE(${cmake})
ENDFOREACH (cmake)
set(CMAKE_CXX_STANDARD 17)

ADD_SUBDIRECTORY(src)
