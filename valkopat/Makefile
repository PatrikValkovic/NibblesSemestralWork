#Variable definitions
USE_SDL = 1
USE_NCURSES = 1
USE_CONSOLE = 1
TARGET_DIR = build

COMPILE_FLAGS = -std=c++11 -Wall -pedantic
COMPILER = g++

#Required
.PHONY: all			#not implemented
.PHONY: compile		#implemented
.PHONY: run			#not implemented
.PHONY: clean		#implemented
.PHONY: doc			#not implemented

#Custom
.PHONY: debug		#implemented
.PHONY: tests		#implemented

compile: Configure
	COMPILE_FLAGS += -O2

debug: Configure
	COMPILE_FLAGS += -g

clean:
	rm -rf $(TARGET_DIR)

tests: Configure

Configure: TargetDir
	ifeq ($(USE_SDL),1)
		COMPILER_FLAGS += -lSDL2 -lSDL2_main -lSDL2_ttf -lSDL2_image -D USE_SDL
	endif
	ifeq ($(USE_NCURSES),1)
		COMPILER_FLAGS += -lncurses -D USE_NCURSES
	endif
	ifeq ($(USE_CONSOLE),1)
    	COMPILER_FLAGS += -D USE_CONSOLE
	endif

TargetDir:
	mkdir $(TARGET_DIR)