# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\docto\Documents\GitHub\Sandbox-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\docto\Documents\GitHub\Sandbox-Engine\build

# Include any dependencies generated for this target.
include CMakeFiles/Sandbox_Engine_Debug.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Sandbox_Engine_Debug.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sandbox_Engine_Debug.dir/flags.make

CMakeFiles/Sandbox_Engine_Debug.dir/src/automata/Solver.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/automata/Solver.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/automata/Solver.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/automata/Solver.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/automata/Solver.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/automata/Solver.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/automata/Solver.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\automata\Solver.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\automata\Solver.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\automata\Solver.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/automata/Solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/automata/Solver.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\automata\Solver.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\automata\Solver.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/automata/Solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/automata/Solver.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\automata\Solver.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\automata\Solver.cpp.s

CMakeFiles/Sandbox_Engine_Debug.dir/src/core/Entity.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/core/Entity.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/core/Entity.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/core/Entity.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/core/Entity.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/core/Entity.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/core/Entity.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\core\Entity.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\core\Entity.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\core\Entity.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/core/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/core/Entity.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\core\Entity.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\core\Entity.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/core/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/core/Entity.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\core\Entity.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\core\Entity.cpp.s

CMakeFiles/Sandbox_Engine_Debug.dir/src/core/FrameBuffer.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/core/FrameBuffer.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/core/FrameBuffer.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/core/FrameBuffer.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/core/FrameBuffer.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/core/FrameBuffer.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/core/FrameBuffer.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\core\FrameBuffer.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\core\FrameBuffer.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\core\FrameBuffer.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/core/FrameBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/core/FrameBuffer.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\core\FrameBuffer.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\core\FrameBuffer.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/core/FrameBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/core/FrameBuffer.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\core\FrameBuffer.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\core\FrameBuffer.cpp.s

CMakeFiles/Sandbox_Engine_Debug.dir/src/external/stb_image/stb_image.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/external/stb_image/stb_image.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/external/stb_image/stb_image.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/external/stb_image/stb_image.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/external/stb_image/stb_image.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/external/stb_image/stb_image.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/external/stb_image/stb_image.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\external\stb_image\stb_image.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\external\stb_image\stb_image.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\external\stb_image\stb_image.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/external/stb_image/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/external/stb_image/stb_image.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\external\stb_image\stb_image.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\external\stb_image\stb_image.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/external/stb_image/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/external/stb_image/stb_image.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\external\stb_image\stb_image.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\external\stb_image\stb_image.cpp.s

CMakeFiles/Sandbox_Engine_Debug.dir/src/main.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/main.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/main.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/main.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/main.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/main.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/main.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\main.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\main.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\main.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/main.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\main.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\main.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/main.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\main.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\main.cpp.s

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/IndexBuffer.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/IndexBuffer.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/IndexBuffer.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/renderer/IndexBuffer.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/IndexBuffer.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/IndexBuffer.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/IndexBuffer.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\IndexBuffer.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\IndexBuffer.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\IndexBuffer.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/IndexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/IndexBuffer.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\IndexBuffer.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\IndexBuffer.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/IndexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/IndexBuffer.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\IndexBuffer.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\IndexBuffer.cpp.s

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/OrthoCamera.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/OrthoCamera.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/OrthoCamera.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/renderer/OrthoCamera.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/OrthoCamera.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/OrthoCamera.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/OrthoCamera.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\OrthoCamera.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\OrthoCamera.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\OrthoCamera.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/OrthoCamera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/OrthoCamera.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\OrthoCamera.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\OrthoCamera.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/OrthoCamera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/OrthoCamera.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\OrthoCamera.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\OrthoCamera.cpp.s

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Renderer.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Renderer.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Renderer.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/renderer/Renderer.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Renderer.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Renderer.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Renderer.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\Renderer.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\Renderer.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\Renderer.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Renderer.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\Renderer.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\Renderer.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Renderer.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\Renderer.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\Renderer.cpp.s

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Shader.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Shader.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Shader.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/renderer/Shader.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Shader.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Shader.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Shader.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\Shader.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\Shader.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\Shader.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Shader.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\Shader.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\Shader.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Shader.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\Shader.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\Shader.cpp.s

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Texture.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Texture.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Texture.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/renderer/Texture.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Texture.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Texture.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Texture.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\Texture.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\Texture.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\Texture.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Texture.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\Texture.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\Texture.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Texture.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\Texture.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\Texture.cpp.s

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexArray.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexArray.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexArray.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/renderer/VertexArray.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexArray.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexArray.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexArray.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\VertexArray.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\VertexArray.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\VertexArray.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexArray.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\VertexArray.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\VertexArray.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexArray.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\VertexArray.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\VertexArray.cpp.s

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBuffer.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBuffer.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBuffer.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/renderer/VertexBuffer.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBuffer.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBuffer.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBuffer.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\VertexBuffer.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\VertexBuffer.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\VertexBuffer.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBuffer.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\VertexBuffer.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\VertexBuffer.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBuffer.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\VertexBuffer.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\VertexBuffer.cpp.s

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBufferLayout.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBufferLayout.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBufferLayout.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/renderer/VertexBufferLayout.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBufferLayout.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBufferLayout.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBufferLayout.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\VertexBufferLayout.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\VertexBufferLayout.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\VertexBufferLayout.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBufferLayout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBufferLayout.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\VertexBufferLayout.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\VertexBufferLayout.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBufferLayout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBufferLayout.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\renderer\VertexBufferLayout.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\renderer\VertexBufferLayout.cpp.s

CMakeFiles/Sandbox_Engine_Debug.dir/src/window/Window.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/flags.make
CMakeFiles/Sandbox_Engine_Debug.dir/src/window/Window.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/includes_CXX.rsp
CMakeFiles/Sandbox_Engine_Debug.dir/src/window/Window.cpp.obj: C:/Users/docto/Documents/GitHub/Sandbox-Engine/src/window/Window.cpp
CMakeFiles/Sandbox_Engine_Debug.dir/src/window/Window.cpp.obj: CMakeFiles/Sandbox_Engine_Debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Sandbox_Engine_Debug.dir/src/window/Window.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sandbox_Engine_Debug.dir/src/window/Window.cpp.obj -MF CMakeFiles\Sandbox_Engine_Debug.dir\src\window\Window.cpp.obj.d -o CMakeFiles\Sandbox_Engine_Debug.dir\src\window\Window.cpp.obj -c C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\window\Window.cpp

CMakeFiles/Sandbox_Engine_Debug.dir/src/window/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox_Engine_Debug.dir/src/window/Window.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\window\Window.cpp > CMakeFiles\Sandbox_Engine_Debug.dir\src\window\Window.cpp.i

CMakeFiles/Sandbox_Engine_Debug.dir/src/window/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox_Engine_Debug.dir/src/window/Window.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\docto\Documents\GitHub\Sandbox-Engine\src\window\Window.cpp -o CMakeFiles\Sandbox_Engine_Debug.dir\src\window\Window.cpp.s

# Object files for target Sandbox_Engine_Debug
Sandbox_Engine_Debug_OBJECTS = \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/automata/Solver.cpp.obj" \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/core/Entity.cpp.obj" \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/core/FrameBuffer.cpp.obj" \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/external/stb_image/stb_image.cpp.obj" \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/main.cpp.obj" \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/IndexBuffer.cpp.obj" \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/OrthoCamera.cpp.obj" \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Renderer.cpp.obj" \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Shader.cpp.obj" \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Texture.cpp.obj" \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexArray.cpp.obj" \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBuffer.cpp.obj" \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBufferLayout.cpp.obj" \
"CMakeFiles/Sandbox_Engine_Debug.dir/src/window/Window.cpp.obj"

# External object files for target Sandbox_Engine_Debug
Sandbox_Engine_Debug_EXTERNAL_OBJECTS =

Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/automata/Solver.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/core/Entity.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/core/FrameBuffer.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/external/stb_image/stb_image.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/main.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/IndexBuffer.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/OrthoCamera.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Renderer.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Shader.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/Texture.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexArray.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBuffer.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/renderer/VertexBufferLayout.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/src/window/Window.cpp.obj
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/build.make
Sandbox_Engine_Debug.exe: C:/Users/docto/Documents/GitHub/Sandbox-Engine/lib/libglfw3.a
Sandbox_Engine_Debug.exe: C:/Users/docto/Documents/GitHub/Sandbox-Engine/lib/libglad.a
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/linkLibs.rsp
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/objects1.rsp
Sandbox_Engine_Debug.exe: CMakeFiles/Sandbox_Engine_Debug.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable Sandbox_Engine_Debug.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sandbox_Engine_Debug.dir\link.txt --verbose=$(VERBOSE)
	"C:\Program Files\CMake\bin\cmake.exe" -E copy_directory C:/Users/docto/Documents/GitHub/Sandbox-Engine/res C:/Users/docto/Documents/GitHub/Sandbox-Engine/build/res

# Rule to build all files generated by this target.
CMakeFiles/Sandbox_Engine_Debug.dir/build: Sandbox_Engine_Debug.exe
.PHONY : CMakeFiles/Sandbox_Engine_Debug.dir/build

CMakeFiles/Sandbox_Engine_Debug.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Sandbox_Engine_Debug.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Sandbox_Engine_Debug.dir/clean

CMakeFiles/Sandbox_Engine_Debug.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\docto\Documents\GitHub\Sandbox-Engine C:\Users\docto\Documents\GitHub\Sandbox-Engine C:\Users\docto\Documents\GitHub\Sandbox-Engine\build C:\Users\docto\Documents\GitHub\Sandbox-Engine\build C:\Users\docto\Documents\GitHub\Sandbox-Engine\build\CMakeFiles\Sandbox_Engine_Debug.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Sandbox_Engine_Debug.dir/depend

