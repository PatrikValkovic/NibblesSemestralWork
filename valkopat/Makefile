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
.PHONY: debug		#not implemented
.PHONY: tests		#implemented

compile: Configure SDLViewModel.o ConsoleViewModel.o NCursesViewModel.o
	COMPILE_FLAGS += -O2

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


NCursesViewModel.o: src/ViewModels/NCURSES/NCursesViewModel.h src/ViewModels/NCURSES/NCursesViewModel.cpp src/ViewModels/BaseViewModel.h
	$(COMPILER) -c src/ViewModels/CONSOLE/ConsoleViewModel.cpp $(COMPILE_FLAGS) -o $(TARGET_DIR)/ConsoleViewModel.o

ConsoleViewModel.o: src/ViewModels/CONSOLE/ConsoleViewModel.h src/ViewModels/CONSOLE/ConsoleViewModel.cpp src/ViewModels/BaseViewModel.h
	g++ -c src/ViewModels/CONSOLE/ConsoleViewModel.cpp -o $(TARGET_DIR)/ConsoleViewModel.o

SDLViewModel.o: src/ViewModels/SDL/SDLViewModel.h src/ViewModels/SDL/SDLViewModel.cpp src/ViewModels/BaseViewModel.h
	$(COMPILER) -c src/ViewModels/SDL/ConsoleViewModel.cpp $(COMPILE_FLAGS) -o $(TARGET_DIR)/SDLViewModel.o