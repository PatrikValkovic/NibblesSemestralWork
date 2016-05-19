#Variable definitions
USE_SDL = 1
USE_NCURSES = 1
USE_CONSOLE = 1
TARGET_DIR = build

COMPILE_FLAGS = -std=c++11 -pthread
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

$(TARGET_DIR)/game.o: $(TARGET_DIR)/main.o $(TARGET_DIR)/NibbleGame.o $(TARGET_DIR)/States.o $(TARGET_DIR)/Exceptions.o
	$(LINKER) -r -o $(TARGET_DIR)/game.o $(TARGET_DIR)/main.o $(TARGET_DIR)/NibbleGame.o $(TARGET_DIR)/States.o $(TARGET_DIR)/Exceptions.o


$(TARGET_DIR)/main.o: src/main.cpp src/Game/NibbleGame.h
	$(COMPILER) -c -o $(TARGET_DIR)/main.o src/main.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/NibbleGame.o: src/ViewModels/ViewModelChooser.h src/Game/NibbleGame.h src/Game/NibbleGame.cpp
	$(COMPILER) -c -o $(TARGET_DIR)/NibbleGame.o src/Game/NibbleGame.cpp $(COMPILE_FLAGS)

##################
##	EXCEPTIONS  ##
##################

$(TARGET_DIR)/Exceptions.o: $(TARGET_DIR)/Exception.o $(TARGET_DIR)/InvalidArgumentException.o
	$(LINKER) -r -o $(TARGET_DIR)/Exceptions.o $(TARGET_DIR)/Exception.o $(TARGET_DIR)/InvalidArgumentException.o

$(TARGET_DIR)/InvalidArgumentException.o: src/Exceptions/InvalidArgumentException.h src/Exceptions/InvalidArgumentException.cpp $(TARGET_DIR)/Exception.o
	$(COMPILER) -c -o $(TARGET_DIR)/InvalidArgumentException.o src/Exceptions/InvalidArgumentException.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/Exception.o: src/Exceptions/Exception.h src/Exceptions/Exception.cpp
	$(COMPILER) -c -o $(TARGET_DIR)/Exception.o src/Exceptions/Exception.cpp $(COMPILE_FLAGS)

#################
##	TRANSLATE  ##
#################

$(TARGET_DIR)/Translate.o : $(TARGET_DIR)/TranslateEngine.o
	$(LINKER) -r -o $(TARGET_DIR)/Translate.o $(TARGET_DIR)/TranslateEngine.o

$(TARGET_DIR)/TranslateEngine.o: src/Translation/TranslateEngine.cpp src/Translation/TranslateEngine.h
	$(COMPILER) -c -o $(TARGET_DIR)/TranslateEngine.o src/Translation/TranslateEngine.cpp $(COMPILE_FLAGS)


##############
##	STATES  ##
##############

$(TARGET_DIR)/States.o: $(TARGET_DIR)/GameStates.o $(TARGET_DIR)/SplashScreenGameState.o $(TARGET_DIR)/MenuGameState.o $(TARGET_DIR)/SingleplayerGameState.o $(TARGET_DIR)/PlayingState.o $(TARGET_DIR)/NetGameState.o $(TARGET_DIR)/MultiplayerGameState.o $(TARGET_DIR)/ChangeLanguageState.o $(TARGET_DIR)/EndState.o $(TARGET_DIR)/GamePauseState.o
	$(LINKER) -r -o $(TARGET_DIR)/States.o $(TARGET_DIR)/GameStates.o $(TARGET_DIR)/SplashScreenGameState.o $(TARGET_DIR)/MenuGameState.o $(TARGET_DIR)/SingleplayerGameState.o $(TARGET_DIR)/PlayingState.o $(TARGET_DIR)/NetGameState.o $(TARGET_DIR)/MultiplayerGameState.o $(TARGET_DIR)/ChangeLanguageState.o $(TARGET_DIR)/EndState.o $(TARGET_DIR)/GamePauseState.o

$(TARGET_DIR)/GameStates.o: src/States/GameStates.cpp src/States/GameStates.h src/States/AbstractGameState.h src/States/MenuGameState.h src/States/SplashScreenGameState.h
	$(COMPILER) -c -o $(TARGET_DIR)/GameStates.o src/States/GameStates.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/SplashScreenGameState.o: src/States/SplashScreenGameState.h src/States/SplashScreenGameState.cpp src/States/AbstractGameState.h
	$(COMPILER) -c -o $(TARGET_DIR)/SplashScreenGameState.o src/States/SplashScreenGameState.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/MenuGameState.o: src/States/MenuGameState.h src/States/MenuGameState.cpp src/States/AbstractGameState.h
	$(COMPILER) -c -o $(TARGET_DIR)/MenuGameState.o src/States/MenuGameState.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/SingleplayerGameState.o: src/States/SingleplayerGameState.h src/States/SingleplayerGameState.cpp src/States/AbstractGameState.h
	$(COMPILER) -c -o $(TARGET_DIR)/SingleplayerGameState.o src/States/SingleplayerGameState.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/PlayingState.o: src/States/PlayingState.h src/States/PlayingState.cpp src/States/AbstractGameState.h
	$(COMPILER) -c -o $(TARGET_DIR)/PlayingState.o src/States/PlayingState.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/NetGameState.o: src/States/NetGameState.h src/States/NetGameState.cpp src/States/AbstractGameState.h
	$(COMPILER) -c -o $(TARGET_DIR)/NetGameState.o src/States/NetGameState.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/MultiplayerGameState.o: src/States/MultiplayerGameState.h src/States/MultiplayerGameState.cpp src/States/AbstractGameState.h
	$(COMPILER) -c -o $(TARGET_DIR)/MultiplayerGameState.o src/States/MultiplayerGameState.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/EndState.o: src/States/EndState.h src/States/EndState.cpp src/States/AbstractGameState.h
	$(COMPILER) -c -o $(TARGET_DIR)/EndState.o src/States/EndState.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/ChangeLanguageState.o: src/States/ChangeLanguageState.h src/States/ChangeLanguageState.cpp src/States/AbstractGameState.h
	$(COMPILER) -c -o $(TARGET_DIR)/ChangeLanguageState.o src/States/ChangeLanguageState.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/GamePauseState.o: src/States/GamePauseState.h src/States/GamePauseState.cpp src/States/AbstractGameState.h
	$(COMPILER) -c -o $(TARGET_DIR)/GamePauseState.o src/States/GamePauseState.cpp $(COMPILE_FLAGS)

src/States/AbstractGameState.h : src/States/StatesNames.h

##################
##	VIEW MODELS ##
##################
__ABSTRACTION_FILES = src/ViewModels/Abstract/SplashPauseScreenAbstractViewModel.h src/ViewModels/Abstract/MenuAbstractViewModel.h src/ViewModels/Abstract/LanguageAbstractViewModel.h src/ViewModels/Abstract/MultiplayerAbstractViewModel.h src/ViewModels/Abstract/NetMenuAbstractViewModel.h src/ViewModels/Abstract/SingpleplayerAbstractViewModel.h src/ViewModels/Abstract/GameAbstractViewModel.h src/ViewModels/Abstract/ScoreAbstractViewModel.h src/ViewModels/Abstract/QuitAbstractViewModel.h

$(TARGET_DIR)/ViewModels.o: $(TARGET_DIR)/ViewModelChooser.o $(TARGET_DIR)/ConsoleModel.o $(TARGET_DIR)/SDLModel.o $(TARGET_DIR)/NCursesModel.o $(TARGET_DIR)/Translate.o
	$(LINKER) -r -o $(TARGET_DIR)/ViewModels.o $(TARGET_DIR)/ViewModelChooser.o $(TARGET_DIR)/ConsoleModel.o $(TARGET_DIR)/SDLModel.o $(TARGET_DIR)/NCursesModel.o $(TARGET_DIR)/Translate.o

$(TARGET_DIR)/ViewModelChooser.o: src/ViewModels/ViewModelChooser.h src/ViewModels/ViewModelChooser.cpp
	$(COMPILER) -o $(TARGET_DIR)/ViewModelChooser.o -c src/ViewModels/ViewModelChooser.cpp $(COMPILE_FLAGS)

## NCURSES
$(TARGET_DIR)/NCursesModel.o: $(TARGET_DIR)/SplashScreenNCursesViewModel.o $(TARGET_DIR)/SingpleplayerMenuNCursesViewModel.o $(TARGET_DIR)/ScoreNCursesViewModel.o $(TARGET_DIR)/NetMenuNCursesViewModel.o $(TARGET_DIR)/MultiplayerNCursesViewModel.o $(TARGET_DIR)/MenuNCursesViewModel.o $(TARGET_DIR)/LanguageNCursesViewModel.o $(TARGET_DIR)/GameNCursesViewModel.o $(TARGET_DIR)/NCursesViewModel.o $(TARGET_DIR)/QuitNCursesViewModel.o
	$(LINKER) -r -o $(TARGET_DIR)/NCursesModel.o $(TARGET_DIR)/SplashScreenNCursesViewModel.o $(TARGET_DIR)/SingpleplayerMenuNCursesViewModel.o $(TARGET_DIR)/ScoreNCursesViewModel.o $(TARGET_DIR)/NetMenuNCursesViewModel.o $(TARGET_DIR)/MultiplayerNCursesViewModel.o $(TARGET_DIR)/MenuNCursesViewModel.o $(TARGET_DIR)/LanguageNCursesViewModel.o $(TARGET_DIR)/NCursesViewModel.o $(TARGET_DIR)/GameNCursesViewModel.o $(TARGET_DIR)/QuitNCursesViewModel.o

$(TARGET_DIR)/NCursesViewModel.o: src/ViewModels/NCURSES/NCursesViewModel.cpp  src/ViewModels/NCURSES/NCursesViewModel.h src/ViewModels/NCURSES/GameNCursesViewModel.h src/ViewModels/NCURSES/LanguageNCursesViewModel.h src/ViewModels/NCURSES/MenuNCursesViewModel.h src/ViewModels/NCURSES/MultiplayerNCursesViewModel.h src/ViewModels/NCURSES/NetMenuNCursesViewModel.h src/ViewModels/NCURSES/ScoreNCursesViewModel.h src/ViewModels/NCURSES/SingpleplayerMenuNCursesViewModel.h src/ViewModels/NCURSES/SplashScreenNCursesViewModel.h  src/ViewModels/NCURSES/QuitNCursesViewModel.h $(__ABSTRACTION_FILES)
	g++ -c -o $(TARGET_DIR)/NCursesViewModel.o src/ViewModels/NCURSES/NCursesViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/GameNCursesViewModel.o: src/ViewModels/NCURSES/GameNCursesViewModel.cpp src/ViewModels/NCURSES/GameNCursesViewModel.h src/ViewModels/Abstract/GameAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/GameNCursesViewModel.o src/ViewModels/NCURSES/GameNCursesViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/LanguageNCursesViewModel.o: src/ViewModels/NCURSES/LanguageNCursesViewModel.cpp src/ViewModels/NCURSES/LanguageNCursesViewModel.h src/ViewModels/Abstract/LanguageAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/LanguageNCursesViewModel.o src/ViewModels/NCURSES/LanguageNCursesViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/MenuNCursesViewModel.o: src/ViewModels/NCURSES/MenuNCursesViewModel.cpp src/ViewModels/NCURSES/MenuNCursesViewModel.h src/ViewModels/Abstract/MenuAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/MenuNCursesViewModel.o src/ViewModels/NCURSES/MenuNCursesViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/MultiplayerNCursesViewModel.o: src/ViewModels/NCURSES/MultiplayerNCursesViewModel.cpp src/ViewModels/NCURSES/MultiplayerNCursesViewModel.h src/ViewModels/Abstract/MultiplayerAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/MultiplayerNCursesViewModel.o src/ViewModels/NCURSES/MultiplayerNCursesViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/NetMenuNCursesViewModel.o: src/ViewModels/NCURSES/NetMenuNCursesViewModel.cpp src/ViewModels/NCURSES/NetMenuNCursesViewModel.h src/ViewModels/Abstract/NetMenuAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/NetMenuNCursesViewModel.o src/ViewModels/NCURSES/NetMenuNCursesViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/ScoreNCursesViewModel.o: src/ViewModels/NCURSES/ScoreNCursesViewModel.cpp src/ViewModels/NCURSES/ScoreNCursesViewModel.h src/ViewModels/Abstract/ScoreAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/ScoreNCursesViewModel.o src/ViewModels/NCURSES/ScoreNCursesViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/SingpleplayerMenuNCursesViewModel.o: src/ViewModels/NCURSES/SingpleplayerMenuNCursesViewModel.cpp src/ViewModels/NCURSES/SingpleplayerMenuNCursesViewModel.h src/ViewModels/Abstract/SingpleplayerAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/SingpleplayerMenuNCursesViewModel.o src/ViewModels/NCURSES/SingpleplayerMenuNCursesViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/SplashScreenNCursesViewModel.o: src/ViewModels/NCURSES/SplashScreenNCursesViewModel.cpp src/ViewModels/NCURSES/SplashScreenNCursesViewModel.h src/ViewModels/Abstract/SplashPauseScreenAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/SplashScreenNCursesViewModel.o src/ViewModels/NCURSES/SplashScreenNCursesViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/QuitNCursesViewModel.o: src/ViewModels/NCURSES/QuitNCursesViewModel.cpp src/ViewModels/NCURSES/QuitNCursesViewModel.h src/ViewModels/Abstract/QuitAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/QuitNCursesViewModel.o src/ViewModels/NCURSES/QuitNCursesViewModel.cpp $(COMPILE_FLAGS)

## SDL
$(TARGET_DIR)/SDLModel.o: $(TARGET_DIR)/SplashScreenSDLViewModel.o $(TARGET_DIR)/SingpleplayerMenuSDLViewModel.o $(TARGET_DIR)/ScoreSDLViewModel.o $(TARGET_DIR)/NetMenuSDLViewModel.o $(TARGET_DIR)/MultiplayerSDLViewModel.o $(TARGET_DIR)/MenuSDLViewModel.o $(TARGET_DIR)/LanguageSDLViewModel.o $(TARGET_DIR)/GameSDLViewModel.o $(TARGET_DIR)/SDLViewModel.o $(TARGET_DIR)/QuitSDLViewModel.o
	$(LINKER) -r -o $(TARGET_DIR)/SDLModel.o $(TARGET_DIR)/SplashScreenSDLViewModel.o $(TARGET_DIR)/SingpleplayerMenuSDLViewModel.o $(TARGET_DIR)/ScoreSDLViewModel.o $(TARGET_DIR)/NetMenuSDLViewModel.o $(TARGET_DIR)/MultiplayerSDLViewModel.o $(TARGET_DIR)/MenuSDLViewModel.o $(TARGET_DIR)/LanguageSDLViewModel.o $(TARGET_DIR)/SDLViewModel.o $(TARGET_DIR)/GameSDLViewModel.o $(TARGET_DIR)/QuitSDLViewModel.o

$(TARGET_DIR)/SDLViewModel.o: src/ViewModels/SDL/SDLViewModel.cpp  src/ViewModels/SDL/SDLViewModel.h src/ViewModels/SDL/GameSDLViewModel.h src/ViewModels/SDL/LanguageSDLViewModel.h src/ViewModels/SDL/MenuSDLViewModel.h src/ViewModels/SDL/MultiplayerSDLViewModel.h src/ViewModels/SDL/NetMenuSDLViewModel.h src/ViewModels/SDL/ScoreSDLViewModel.h src/ViewModels/SDL/SingpleplayerMenuSDLViewModel.h src/ViewModels/SDL/SplashScreenSDLViewModel.h src/ViewModels/SDL/QuitSDLViewModel.h $(__ABSTRACTION_FILES)
	g++ -c -o $(TARGET_DIR)/SDLViewModel.o src/ViewModels/SDL/SDLViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/GameSDLViewModel.o: src/ViewModels/SDL/GameSDLViewModel.cpp src/ViewModels/SDL/GameSDLViewModel.h src/ViewModels/Abstract/GameAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/GameSDLViewModel.o src/ViewModels/SDL/GameSDLViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/LanguageSDLViewModel.o: src/ViewModels/SDL/LanguageSDLViewModel.cpp src/ViewModels/SDL/LanguageSDLViewModel.h src/ViewModels/Abstract/LanguageAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/LanguageSDLViewModel.o src/ViewModels/SDL/LanguageSDLViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/MenuSDLViewModel.o: src/ViewModels/SDL/MenuSDLViewModel.cpp src/ViewModels/SDL/MenuSDLViewModel.h src/ViewModels/Abstract/MenuAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/MenuSDLViewModel.o src/ViewModels/SDL/MenuSDLViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/MultiplayerSDLViewModel.o: src/ViewModels/SDL/MultiplayerSDLViewModel.cpp src/ViewModels/SDL/MultiplayerSDLViewModel.h src/ViewModels/Abstract/MultiplayerAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/MultiplayerSDLViewModel.o src/ViewModels/SDL/MultiplayerSDLViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/NetMenuSDLViewModel.o: src/ViewModels/SDL/NetMenuSDLViewModel.cpp src/ViewModels/SDL/NetMenuSDLViewModel.h src/ViewModels/Abstract/NetMenuAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/NetMenuSDLViewModel.o src/ViewModels/SDL/NetMenuSDLViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/ScoreSDLViewModel.o: src/ViewModels/SDL/ScoreSDLViewModel.cpp src/ViewModels/SDL/ScoreSDLViewModel.h src/ViewModels/Abstract/ScoreAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/ScoreSDLViewModel.o src/ViewModels/SDL/ScoreSDLViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/SingpleplayerMenuSDLViewModel.o: src/ViewModels/SDL/SingpleplayerMenuSDLViewModel.cpp src/ViewModels/SDL/SingpleplayerMenuSDLViewModel.h src/ViewModels/Abstract/SingpleplayerAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/SingpleplayerMenuSDLViewModel.o src/ViewModels/SDL/SingpleplayerMenuSDLViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/SplashScreenSDLViewModel.o: src/ViewModels/SDL/SplashScreenSDLViewModel.cpp src/ViewModels/SDL/SplashScreenSDLViewModel.h src/ViewModels/Abstract/SplashPauseScreenAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/SplashScreenSDLViewModel.o src/ViewModels/SDL/SplashScreenSDLViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/QuitSDLViewModel.o: src/ViewModels/SDL/QuitSDLViewModel.cpp src/ViewModels/SDL/QuitSDLViewModel.h src/ViewModels/Abstract/QuitAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/QuitSDLViewModel.o src/ViewModels/SDL/QuitSDLViewModel.cpp $(COMPILE_FLAGS)

## CONSOLE
$(TARGET_DIR)/ConsoleModel.o: $(TARGET_DIR)/SplashPauseScreenConsoleViewModel.o $(TARGET_DIR)/SingpleplayerMenuConsoleViewModel.o $(TARGET_DIR)/ScoreConsoleViewModel.o $(TARGET_DIR)/NetMenuConsoleViewModel.o $(TARGET_DIR)/MultiplayerConsoleViewModel.o $(TARGET_DIR)/MenuConsoleViewModel.o $(TARGET_DIR)/LanguageConsoleViewModel.o $(TARGET_DIR)/GameConsoleViewModel.o $(TARGET_DIR)/ConsoleViewModel.o $(TARGET_DIR)/QuitConsoleViewModel.o
	$(LINKER) -r -o $(TARGET_DIR)/ConsoleModel.o $(TARGET_DIR)/SplashPauseScreenConsoleViewModel.o $(TARGET_DIR)/SingpleplayerMenuConsoleViewModel.o $(TARGET_DIR)/ScoreConsoleViewModel.o $(TARGET_DIR)/NetMenuConsoleViewModel.o $(TARGET_DIR)/MultiplayerConsoleViewModel.o $(TARGET_DIR)/MenuConsoleViewModel.o $(TARGET_DIR)/LanguageConsoleViewModel.o $(TARGET_DIR)/ConsoleViewModel.o $(TARGET_DIR)/GameConsoleViewModel.o $(TARGET_DIR)/QuitConsoleViewModel.o

$(TARGET_DIR)/ConsoleViewModel.o: src/ViewModels/CONSOLE/ConsoleViewModel.cpp  src/ViewModels/CONSOLE/ConsoleViewModel.h src/ViewModels/CONSOLE/GameConsoleViewModel.h src/ViewModels/CONSOLE/LanguageConsoleViewModel.h src/ViewModels/CONSOLE/MenuConsoleViewModel.h src/ViewModels/CONSOLE/MultiplayerConsoleViewModel.h src/ViewModels/CONSOLE/NetMenuConsoleViewModel.h src/ViewModels/CONSOLE/ScoreConsoleViewModel.h src/ViewModels/CONSOLE/SingpleplayerMenuConsoleViewModel.h src/ViewModels/CONSOLE/SplashPauseScreenConsoleViewModel.h src/ViewModels/CONSOLE/QuitConsoleViewModel.h $(__ABSTRACTION_FILES)
	g++ -c -o $(TARGET_DIR)/ConsoleViewModel.o src/ViewModels/CONSOLE/ConsoleViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/GameConsoleViewModel.o: src/ViewModels/CONSOLE/GameConsoleViewModel.cpp src/ViewModels/CONSOLE/GameConsoleViewModel.h src/ViewModels/Abstract/GameAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/GameConsoleViewModel.o src/ViewModels/CONSOLE/GameConsoleViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/LanguageConsoleViewModel.o: src/ViewModels/CONSOLE/LanguageConsoleViewModel.cpp src/ViewModels/CONSOLE/LanguageConsoleViewModel.h src/ViewModels/Abstract/LanguageAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/LanguageConsoleViewModel.o src/ViewModels/CONSOLE/LanguageConsoleViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/MenuConsoleViewModel.o: src/ViewModels/CONSOLE/MenuConsoleViewModel.cpp src/ViewModels/CONSOLE/MenuConsoleViewModel.h src/ViewModels/Abstract/MenuAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/MenuConsoleViewModel.o src/ViewModels/CONSOLE/MenuConsoleViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/MultiplayerConsoleViewModel.o: src/ViewModels/CONSOLE/MultiplayerConsoleViewModel.cpp src/ViewModels/CONSOLE/MultiplayerConsoleViewModel.h src/ViewModels/Abstract/MultiplayerAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/MultiplayerConsoleViewModel.o src/ViewModels/CONSOLE/MultiplayerConsoleViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/NetMenuConsoleViewModel.o: src/ViewModels/CONSOLE/NetMenuConsoleViewModel.cpp src/ViewModels/CONSOLE/NetMenuConsoleViewModel.h src/ViewModels/Abstract/NetMenuAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/NetMenuConsoleViewModel.o src/ViewModels/CONSOLE/NetMenuConsoleViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/ScoreConsoleViewModel.o: src/ViewModels/CONSOLE/ScoreConsoleViewModel.cpp src/ViewModels/CONSOLE/ScoreConsoleViewModel.h src/ViewModels/Abstract/ScoreAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/ScoreConsoleViewModel.o src/ViewModels/CONSOLE/ScoreConsoleViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/SingpleplayerMenuConsoleViewModel.o: src/ViewModels/CONSOLE/SingpleplayerMenuConsoleViewModel.cpp src/ViewModels/CONSOLE/SingpleplayerMenuConsoleViewModel.h src/ViewModels/Abstract/SingpleplayerAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/SingpleplayerMenuConsoleViewModel.o src/ViewModels/CONSOLE/SingpleplayerMenuConsoleViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/SplashPauseScreenConsoleViewModel.o: src/ViewModels/CONSOLE/SplashPauseScreenConsoleViewModel.cpp src/ViewModels/CONSOLE/SplashPauseScreenConsoleViewModel.h src/ViewModels/Abstract/SplashPauseScreenAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/SplashPauseScreenConsoleViewModel.o src/ViewModels/CONSOLE/SplashPauseScreenConsoleViewModel.cpp $(COMPILE_FLAGS)

$(TARGET_DIR)/QuitConsoleViewModel.o: src/ViewModels/CONSOLE/QuitConsoleViewModel.cpp src/ViewModels/CONSOLE/QuitConsoleViewModel.h src/ViewModels/Abstract/QuitAbstractViewModel.h
	g++ -c -o $(TARGET_DIR)/QuitConsoleViewModel.o src/ViewModels/CONSOLE/QuitConsoleViewModel.cpp $(COMPILE_FLAGS)
