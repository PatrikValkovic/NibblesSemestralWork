#Variable definitions
USE_SDL = 1
USE_NCURSES = 1
USE_CONSOLE = 1
TARGET_DIR = build

COMPILE_FLAGS = -std=c++11
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
.PHONY: release		#implemented


#Base actions
all: compile doc

compile: | Configure nibbles.exe
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

release: | Release compile

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
	$(eval COMPILE_FLAGS = $(COMPILE_FLAGS) -O2 -D RELEASE)

Debug:
	$(eval COMPILE_FLAGS = $(COMPILE_FLAGS) -g -Wall -pedantic -D DEBUG)



########################
##  FINAL COMPILATION ##
########################

nibbles.exe: $(TARGET_DIR)/nibbles.exe
	cp $(TARGET_DIR)/nibbles.exe ./nibbles.exe

$(TARGET_DIR)/nibbles.exe: $(TARGET_DIR)/all.o $(TARGET_DIR)/ViewModels.o
	$(COMPILER) -o $(TARGET_DIR)/nibbles.exe $(TARGET_DIR)/all.o $(TARGET_DIR)/ViewModels.o $(COMPILE_FLAGS)

$(TARGET_DIR)/all.o: $(TARGET_DIR)/game.o
	$(LINKER) -r -o $(TARGET_DIR)/all.o $(TARGET_DIR)/game.o

############
##	GAME  ##
############

$(TARGET_DIR)/game.o: $(TARGET_DIR)/main.o $(TARGET_DIR)/NibbleGame.o
	$(LINKER) -r -o $(TARGET_DIR)/game.o $(TARGET_DIR)/main.o $(TARGET_DIR)/NibbleGame.o


$(TARGET_DIR)/main.o: src/main.cpp src/Game/NibbleGame.h
	$(COMPILER) -o $(TARGET_DIR)/main.o -c src/main.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/NibbleGame.o: src/ViewModels/ViewModelChooser.h src/Game/NibbleGame.h src/Game/NibbleGame.cpp
	$(COMPILER) -o $(TARGET_DIR)/NibbleGame.o -c src/Game/NibbleGame.cpp




##################
##	VIEW MODELS ##
##################
__ABSTRACTION_FILES = src/ViewModels/Abstract/SplashScreenAbstractViewModel.h src/ViewModels/Abstract/MenuAbstractViewModel.h src/ViewModels/Abstract/LanguageAbstractViewModel.h src/ViewModels/Abstract/MultiplayerAbstractViewModel.h src/ViewModels/Abstract/NetMenuAbstractViewModel.h src/ViewModels/Abstract/SingpleplayerAbstractViewModel.h src/ViewModels/Abstract/GameAbstractViewModel.h src/ViewModels/Abstract/ScoreAbstractViewModel.h

$(TARGET_DIR)/ViewModels.o: $(TARGET_DIR)/ViewModelChooser.o $(TARGET_DIR)/NCursesViewModel.o $(TARGET_DIR)/ConsoleViewModel.o $(TARGET_DIR)/SDLViewModel.o
	$(LINKER) -r -o $(TARGET_DIR)/ViewModels.o $(TARGET_DIR)/ViewModelChooser.o $(TARGET_DIR)/NCursesViewModel.o $(TARGET_DIR)/ConsoleViewModel.o $(TARGET_DIR)/SDLViewModel.o

$(TARGET_DIR)/ViewModelChooser.o: src/ViewModels/ViewModelChooser.h src/ViewModels/ViewModelChooser.cpp
	$(COMPILER) -o $(TARGET_DIR)/ViewModelChooser.o -c src/ViewModels/ViewModelChooser.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/NCursesViewModel.o: src/ViewModels/NCURSES/NCursesViewModel.h src/ViewModels/NCURSES/NCursesViewModel.cpp $(__ABSTRACTION_FILES)
	$(COMPILER) -o $(TARGET_DIR)/NCursesViewModel.o -c src/ViewModels/NCURSES/NCursesViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/ConsoleViewModel.o: src/ViewModels/CONSOLE/ConsoleViewModel.h src/ViewModels/CONSOLE/ConsoleViewModel.cpp $(__ABSTRACTION_FILES)
	$(COMPILER) -o $(TARGET_DIR)/ConsoleViewModel.o -c src/ViewModels/CONSOLE/ConsoleViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/SDLViewModel.o: src/ViewModels/SDL/SDLViewModel.h src/ViewModels/SDL/SDLViewModel.cpp $(__ABSTRACTION_FILES)
	$(COMPILER) -o $(TARGET_DIR)/SDLViewModel.o -c src/ViewModels/SDL/SDLViewModel.cpp $(COMPILE_FLAGS)
