cmake_minimum_required(VERSION 3.3)
project(cpp-test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Threads REQUIRED)

if ($ENV{GOOGLETEST_DIR})
    SET(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
else ()
    message(WARNING "Using googletest src dir specified at Qt Creator wizard")
    SET(GOOGLETEST_DIR "/usr/src")
endif ()
if (EXISTS ${GOOGLETEST_DIR})
    SET(GTestSrc ${GOOGLETEST_DIR}/gtest)
    SET(GMockSrc ${GOOGLETEST_DIR}/gmock)
else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()


include_directories(${GTestSrc} ${GTestSrc}/include ${GMockSrc} ${GMockSrc}/include)

add_executable(PropertyShadowing PropertyShadowing.cpp)
add_test(${PROJECT_NAME} COMMAND ${PROJECT_NAME})
