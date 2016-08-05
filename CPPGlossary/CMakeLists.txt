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

###### Build Locations ######
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

###### Project Files ######
# Headers
set(HEADERS
	include/app_conf.hpp
	include/const_macro.hpp
	include/typedefs.hpp
  )
MESSAGE(STATUS "Added: " ${HEADERS})

# Sources  
set(SOURCES
    src/application_main.cpp
	)
MESSAGE(STATUS "Added: " ${SOURCES})

# Include Directories
include_directories(
	include
)

###### Build Type ######
# Executable
SET(EXE_SOURCES ${HEADERS} ${SOURCES})
add_executable(${CPPG_PROJECT_NAME} ${EXE_SOURCES})

###### Custom Sets ######
# Set warning level
if(MSVC)
  # Force to always compile with Wall
  # For other warning level replace /Wall with /W[0-4] (e.g. /W2 for level warning 2)
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/Wall" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

# Ignore specific warnings (only works with MSVC)
if(MSVC)
  add_definitions( "/wd4514 /wd4619 /wd4710 /wd4711 /wd4820" )
endif()
