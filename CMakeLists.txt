cmake_minimum_required(VERSION 3.2)

project("NanoTekSpice" CXX)

set(PROJECT_BINARY_BIN "bin")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_BIN})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_CONFIGURATION_TYPES Release Debug)
set(CMAKE_SUPPRESS_REGENERATION ON)

if (MSVC)
	# Multicore build with Visual Studio
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
else ()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif ()

include_directories("include")

file(GLOB_RECURSE NANO_HEADERS "include/*.hpp")
file(GLOB_RECURSE NANO_SOURCES "src/*.cpp")

add_executable("nanotekspice" ${NANO_SOURCES} ${NANO_HEADERS})

if (WIN32)
	install(TARGETS "nanotekspice" DESTINATION ".")
else ()
	install(TARGETS "nanotekspice" DESTINATION "bin")
endif ()
