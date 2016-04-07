#Variable definitions
USE_SDL = 1
USE_NCURSES = 1
USE_CONSOLE = 1
TARGET_DIR = build

COMPILE_FLAGS = -Wall -pedantic -std=c++11
COMPILER = g++
LINKER = ld



#Required
.PHONY: all			#implemented
.PHONY: compile		#implemented
.PHONY: run			#implemented
.PHONY: clean		#implemented
.PHONY: doc			#implemented TODO

#Custom
.PHONY: debug		#not implemented
.PHONY: tests		#not implemented



#Base actions
all: compile doc

compile: | Release Configure nibbles.exe
	chmod +x nibbles.exe

run: compile
	./nibbles.exe

clean:
	[ ! -d $(TARGET_DIR) ] || rm -rf $(TARGET_DIR)
	[ ! -x nibbles.exe ] || rm nibbles.exe
	@echo Cleaned

doc:
	@echo DocGenerating

debug: | Debug compile


Configure: TargetDir
ifeq ($(USE_SDL),1)
	$(eval COMPILE_FLAGS = $(COMPILE_FLAGS) -lSDL2 -lSDL2_ttf -lSDL2_image -D USE_SDL)
	$(eval LINKER_FLAGS = $(LINKER_FLAGS) -lSDL2 -lSDL2_ttf -lSDL2_image)
endif
ifeq ($(USE_NCURSES),1)
	$(eval COMPILE_FLAGS = $(COMPILE_FLAGS) -lncurses -D USE_NCURSES)
	$(eval LINKER_FLAGS = $(LINKER_FLAGS) -lncurses)
endif
ifeq ($(USE_CONSOLE),1)
	$(eval COMPILE_FLAGS = $(COMPILE_FLAGS) -D USE_CONSOLE)
endif

TargetDir:
	[ -d $(TARGET_DIR) ] || mkdir $(TARGET_DIR)

Release:
	$(eval COMPILE_FLAGS = $(COMPILE_FLAGS) -O2)

Debug:
	$(eval COMPILE_FLAGS = $(COMPILE_FLAGS) -g)




#callbacks

nibbles.exe: $(TARGET_DIR)/main.o $(TARGET_DIR)/ViewModels.o
	$(COMPILER) -o nibbles.exe $(TARGET_DIR)/main.o $(TARGET_DIR)/ViewModels.o $(COMPILE_FLAGS)

$(TARGET_DIR)/main.o: src/main.cpp src/ViewModels/ViewModelChooser.h
	$(COMPILER) -c src/main.cpp $(COMPILE_FLAGS) -o $(TARGET_DIR)/main.o

$(TARGET_DIR)/ViewModels.o: $(TARGET_DIR)/ViewModelChooser.o $(TARGET_DIR)/NCursesViewModel.o $(TARGET_DIR)/ConsoleViewModel.o $(TARGET_DIR)/SDLViewModel.o
	$(LINKER) -r -o $(TARGET_DIR)/ViewModels.o $(TARGET_DIR)/ViewModelChooser.o $(TARGET_DIR)/NCursesViewModel.o $(TARGET_DIR)/ConsoleViewModel.o $(TARGET_DIR)/SDLViewModel.o

$(TARGET_DIR)/ViewModelChooser.o: src/ViewModels/ViewModelChooser.h src/ViewModels/ViewModelChooser.cpp src/ViewModels/ViewModelChooser.h
	$(COMPILER) -c src/ViewModels/ViewModelChooser.cpp $(COMPILE_FLAGS) -o $(TARGET_DIR)/ViewModelChooser.o

$(TARGET_DIR)/NCursesViewModel.o: src/ViewModels/NCURSES/NCursesViewModel.h src/ViewModels/NCURSES/NCursesViewModel.cpp src/ViewModels/BaseViewModel.h
	$(COMPILER) -c src/ViewModels/NCURSES/NCursesViewModel.cpp $(COMPILE_FLAGS) -o $(TARGET_DIR)/NCursesViewModel.o

$(TARGET_DIR)/ConsoleViewModel.o: src/ViewModels/CONSOLE/ConsoleViewModel.h src/ViewModels/CONSOLE/ConsoleViewModel.cpp src/ViewModels/BaseViewModel.h
	$(COMPILER) -c src/ViewModels/CONSOLE/ConsoleViewModel.cpp $(COMPILE_FLAGS) -o $(TARGET_DIR)/ConsoleViewModel.o

$(TARGET_DIR)/SDLViewModel.o: src/ViewModels/SDL/SDLViewModel.h src/ViewModels/SDL/SDLViewModel.cpp src/ViewModels/BaseViewModel.h
	$(COMPILER) -c src/ViewModels/SDL/SDLViewModel.cpp $(COMPILE_FLAGS) -o $(TARGET_DIR)/SDLViewModel.o
