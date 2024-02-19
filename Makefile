EXENAME    = main.exe

SOURCE     = ./src
BUILD_PATH = ./build
MAIN_FILE  = ./src/main.cpp
IDIR       = ./include
LDIR       = ./lib
GLAD       = ./src/glad.c

LIB_FLAGS  = -L$(LDIR) -lglfw3 -lglad -lgdi32
INC_FLAGS  = -I$(IDIR) -I$(IDIR)/renderer

# Flags:
CXXFLAGS   = -std=c++1y -c -g -O0 -Wall -Wextra -pedantic $(INC_FLAGS)
LDFLAGS    = -std=c++1y $(LIB_FLAGS) 
CXX        = g++

CPP_FILES  += $(wildcard $(SOURCE)/*.cpp)
CPP_FILES  += $(wildcard $(SOURCE)/**/*.cpp)
OBJ_FILES  := $(patsubst $(SOURCE)/%.cpp, $(BUILD_PATH)/%.o, $(CPP_FILES))
# $(patsubst $(SOURCE)/%.cpp, $(BUILD_PATH)/%.o, $(CPP_FILES))
# OBJ_FILES  += $(patsubst $(GLAD), $(BUILD_PATH)/%.o, $(CPP_FILES))

all: $(EXENAME)

$(EXENAME): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) $(LDFLAGS) -o $(BUILD_PATH)/$(EXENAME)

$(BUILD_PATH)/%.o: $(SOURCE)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# .PHONY : clean

# clean:
# ifeq ($(OS),Windows_NT)
# 	del /Q $(subst /,\,$(OBJ_FILES) $(BUILD_PATH)\$(EXENAME))
# else
# 	rm -f $(OBJ_FILES) $(BUILD_PATH)/$(EXENAME)
# endif

# THIS IS WHAT IM TRYING TO DO 
# g++ -g -I./include ./src/main.cpp -L./lib -lglfw3 -lglad -lgdi32 -o main.exe 

# Code to compile glad into static library
# g++ -c I./include ./src/glad.c -o ./build/glad.o
# ar rcs ./lib/libglad.a ./build/glad.o
