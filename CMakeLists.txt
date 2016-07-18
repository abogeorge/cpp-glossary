# CMakeLists.txt
# Author: Abordioaie George

MESSAGE(STATUS "### CPP GLOSSARY ###")

# User defined macros
SET (CPPG_PROJECT_NAME_ROOT CPPGlossary)

# Solution name
project(${CPPG_PROJECT_NAME_ROOT})

# CMake minimum version required
cmake_minimum_required(VERSION 2.8.2)

# General Configuration
set(EX_PLATFORM 64 CACHE STRING 64)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

## Modules
# CPP Glossary
add_subdirectory(CPPGlossary)
