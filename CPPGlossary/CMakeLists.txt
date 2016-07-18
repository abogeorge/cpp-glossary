# CPPGlossary/CMakeLists.txt
# Author: Abordioaie George

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../CMake/;${PROJECT_SOURCE_DIR}/CMake/;${CMAKE_ROOT}/Modules;${CMAKE_MODULE_PATH}")

MESSAGE(STATUS "## CPP GLOSSARY ##")

# CMake minimum version required
cmake_minimum_required(VERSION 2.8.2)

# User defined macros
SET (CPPG_PROJECT_NAME CppGlossary)

# Project Name
PROJECT (${CPPG_PROJECT_NAME})

# Build Locations
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

## Project Files
# Headers
set(HEADERS
	include/header.h
  )
MESSAGE(STATUS "Added: " ${HEADERS})

# Sources  
set(SOURCES
    src/application_main.cpp
	)
MESSAGE(STATUS "Added: " ${SOURCES})

## Build Type
# Executable
SET(EXE_SOURCES ${HEADERS} ${SOURCES})
add_executable(${CPPG_PROJECT_NAME} ${EXE_SOURCES})
