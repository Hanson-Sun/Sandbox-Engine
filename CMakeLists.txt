# OKAY THIS LITERALLY DOESNT WORK I NEED TO FIX IT

cmake_minimum_required(VERSION 3.5)
project(Sandbox_Engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set variables for the include and source directories
set(INC_DIR include)
set(SRC_DIR src)
set(LIB_DIR lib)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_CXX_FLAGS "-pedantic")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "/W4")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
else()
    message("Using another compiler")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Linker: ${CMAKE_LINKER}")

set(LIBRARY_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/external/glad/glad.c

)

add_library(GLAD STATIC ${LIBRARY_SOURCES})

target_include_directories(GLAD PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/external/glad
    # add more directories as needed
)

# i should switch to recursive directory search
include_directories(
    ${CMAKE_SOURCE_DIR}/${INC_DIR}
    ${CMAKE_SOURCE_DIR}/${INC_DIR}/external
    ${CMAKE_SOURCE_DIR}/${INC_DIR}/external/glm
    ${CMAKE_SOURCE_DIR}/${INC_DIR}/external/GLFW
    ${CMAKE_SOURCE_DIR}/${INC_DIR}/external/glad
    ${CMAKE_SOURCE_DIR}/${INC_DIR}/external/KHR
    ${CMAKE_SOURCE_DIR}/${INC_DIR}/external/stb_image
    ${CMAKE_SOURCE_DIR}/${INC_DIR}/renderer
    ${CMAKE_SOURCE_DIR}/${INC_DIR}/window
    ${CMAKE_SOURCE_DIR}/${INC_DIR}/core
    ${CMAKE_SOURCE_DIR}/${INC_DIR}/automata
    ${CMAKE_SOURCE_DIR}/${INC_DIR}/utils
)

file(GLOB_RECURSE HEADER_FILES "${INC_DIR}/*.h" "${INC_DIR}/*.hpp")
file(GLOB_RECURSE SOURCE_FILES "${SRC_DIR}/*.cpp" "{SRC_DIR}/*.c")

message(STATUS "Source files: ${SOURCE_FILES}")

link_directories(${CMAKE_SOURCE_DIR}/${LIB_DIR})


add_executable(${PROJECT_NAME}_${CMAKE_BUILD_TYPE} ${HEADER_FILES} ${SOURCE_FILES})

add_custom_command(TARGET ${PROJECT_NAME}_${CMAKE_BUILD_TYPE} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}_${CMAKE_BUILD_TYPE}>/res)

# libraries 

message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("LIB_DIR: ${LIB_DIR}")
find_library(GLFW3_LIBRARY glfw3 PATHS ${CMAKE_SOURCE_DIR}/${LIB_DIR})
# find_library(GLAD_LIBRARY glad PATHS ${CMAKE_SOURCE_DIR}/${LIB_DIR})
message("GLFW3_LIBRARY: ${GLFW3_LIBRARY}")
# message("GLAD_LIBRARY: ${GLAD_LIBRARY}")

target_link_libraries(${PROJECT_NAME}_${CMAKE_BUILD_TYPE} ${GLFW3_LIBRARY} GLAD)




# if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
#     message("Building for Windows")
# 	target_link_libraries(${PROJECT_NAME}_${CMAKE_BUILD_TYPE} gdi32)
# else()
#     message("Not building for Windows")
#     # Add commands for other systems here
# endif()

# # OpenGL
# set(OpenGL_GL_PREFERENCE GLVND)
# find_package(OpenGL REQUIRED)

# # GLM
# find_package(GLM REQUIRED)
# message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")

# # GLFW
# find_package(GLFW3 REQUIRED)
# message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")

# # GLAD
# add_library(GLAD "thirdparty/glad.c")

# # Put all libraries into a variable
# set(LIBS ${GLFW3_LIBRARY} ${OPENGL_LIBRARY} GLAD ${CMAKE_DL_LIBS} ${ASSIMP_LIBRARY} STB_IMAGE)






# cmake_minimum_required(VERSION 3.5)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -target x86_64-w64-mingw32")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -target x86_64-w64-mingw32")
# message("CXX Standard: ${CMAKE_CXX_STANDARD}")
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "-O0 -Wall -Wextra -pedantic")

# project(Sandbox-Engine)

# # Add .lib files
# link_directories(${CMAKE_SOURCE_DIR}/lib)

# # Add source files
# file(GLOB_RECURSE SOURCE_FILES 
# 	${CMAKE_SOURCE_DIR}/src/*.c
# 	${CMAKE_SOURCE_DIR}/src/*.cpp)
	
# # Add header files
# file(GLOB_RECURSE HEADER_FILES 
# 	${CMAKE_SOURCE_DIR}/include/*.h
# 	${CMAKE_SOURCE_DIR}/include/*.hpp
#     ${CMAKE_SOURCE_DIR}/src/*.h
# 	${CMAKE_SOURCE_DIR}/src/*.hpp)

# # Configure assets header file
# # configure_file(src/helpers/RootDir.h.in src/helpers/RootDir.h)
# include_directories(${CMAKE_BINARY_DIR}/src)
	
# # Define the executable
# add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

# # We need a CMAKE_DIR with some code to find external dependencies
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# #######################################
# # LOOK for the packages that we need! #
# #######################################

# # OpenGL
# set(OpenGL_GL_PREFERENCE GLVND)
# find_package(OpenGL REQUIRED)

# # GLM
# find_package(GLM REQUIRED)
# message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")

# # GLFW
# find_package(GLFW3 REQUIRED)
# message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")

# # GLAD
# add_library(GLAD "thirdparty/glad.c")

# # Put all libraries into a variable
# set(LIBS ${GLFW3_LIBRARY} ${OPENGL_LIBRARY} GLAD ${CMAKE_DL_LIBS} ${ASSIMP_LIBRARY} STB_IMAGE)

# # Define the include DIRs
# include_directories(
# 	"${CMAKE_SOURCE_DIR}/src"
# 	"${CMAKE_SOURCE_DIR}/include"
# 	"${CMAKE_SOURCE_DIR}/include/glad"
# 	"${CMAKE_SOURCE_DIR}/include/glm"
#     "${CMAKE_SOURCE_DIR}/include/KHR"
# )

# # Define the link libraries
# target_link_libraries(${PROJECT_NAME} ${LIBS})

# # Create virtual folders to make it look nicer in VS
# if(MSVC_IDE)
# 	# Macro to preserve source files hierarchy in the IDE
# 	macro(GroupSources curdir)
# 		file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)

# 		foreach(child ${children})
# 			if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
# 				GroupSources(${curdir}/${child})
# 			else()
# 				string(REPLACE "/" "\\" groupname ${curdir})
# 				string(REPLACE "src" "Sources" groupname ${groupname})
# 				source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
# 			endif()
# 		endforeach()
# 	endmacro()

# 	# Run macro
# 	GroupSources(src)
# endif()

# # Copy dlls
# if(WIN32)
# 	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
# 		COMMAND ${CMAKE_COMMAND} -E copy_directory
# 		"${PROJECT_SOURCE_DIR}/dlls"
# 		$<TARGET_FILE_DIR:${PROJECT_NAME}>)
# endif()