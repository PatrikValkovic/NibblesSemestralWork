#Variable definitions
USE_SDL = 0
USE_NCURSES = 0
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
.PHONY: doc			#implemented

#Custom
.PHONY: debug		#implemented
.PHONY: tests		#implemented
.PHONY: release		#implemented


#Base actions
all: compile doc

compile: | Configure valkopat

run: compile
	./valkopat

clean:
	[ ! -d $(TARGET_DIR) ] || rm -rf $(TARGET_DIR)
	[ ! -d doc ] || rm -rf doc
	[ ! -x valkopat ] || rm valkopat
	@echo Cleaned

doc:
	[ ! -d doc ] || mkdir doc
	doxygen doxygen.cfg

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

valkopat: $(TARGET_DIR)/nibbles.exe
	cp $< $@
	chmod +x $@

$(TARGET_DIR)/nibbles.exe: $(TARGET_DIR)/all.o $(TARGET_DIR)/ViewModels.o
	$(COMPILER) -o $@ $^ $(COMPILE_FLAGS)

$(TARGET_DIR)/all.o: $(TARGET_DIR)/game.o $(TARGET_DIR)/Exceptions.o
	$(LINKER) -r -o $@ $^

############
##	GAME  ##
############

$(TARGET_DIR)/game.o: $(TARGET_DIR)/main.o $(TARGET_DIR)/NibbleGame.o $(TARGET_DIR)/States.o $(TARGET_DIR)/GameEntities.o $(TARGET_DIR)/Events.o $(TARGET_DIR)/Tasks.o $(TARGET_DIR)/AIFactory.o $(TARGET_DIR)/NetworkCommunication.o
	$(LINKER) -r -o $@ $^

$(TARGET_DIR)/main.o: src/main.cpp
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/NibbleGame.o: src/Game/NibbleGame.cpp src/Game/NibbleGame.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/GameEntities.o: $(TARGET_DIR)/Worm.o $(TARGET_DIR)/Point.o $(TARGET_DIR)/PlaygroundFactory.o $(TARGET_DIR)/Playground.o $(TARGET_DIR)/GameContent.o $(TARGET_DIR)/Settings.o
	$(LINKER) -r -o $@ $^

$(TARGET_DIR)/Worm.o: src/Game/Worm.cpp src/Game/Worm.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/Point.o: src/Game/Point.cpp src/Game/Point.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/PlaygroundFactory.o: src/Game/PlaygroundFactory.cpp src/Game/PlaygroundFactory.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/Playground.o: src/Game/PlayGround.cpp src/Game/PlayGround.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/GameContent.o: src/Game/GameContent.cpp src/Game/GameContent.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/Settings.o: src/Game/Settings.cpp src/Game/Settings.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/AIFactory.o: src/Game/AIFactory.cpp src/Game/AIFactory.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/NetworkCommunication.o: src/Game/NetworkCommunication.cpp src/Game/NetworkCommunication.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

src/Game/AIFactory.h: src/Exceptions/InvalidArgumentException.h src/Game/Tasks/RandomAI.h src/Game/Tasks/BFSAI.h

src/Game/GameContent.h: src/Game/Worm.h src/Game/PlayGround.h src/Game/Events/EventContainer.h src/Game/Tasks/BaseTask.h

src/Game/NetworkCommunication.h: src/Exceptions/ServerException.h src/Game/Enums.h

src/Game/NibbleGame.h: src/ViewModels/Abstract/BaseViewModel.h src/States/GameStates.h

src/Game/PlayGround.h: src/Exceptions/OutOfRangeException.h src/Game/Enums.h src/Game/Point.h

src/Game/PlaygroundFactory.h: src/Exceptions/OutOfRangeException.h src/Exceptions/InvalidArgumentException.h src/Exceptions/InvalidFormatException.h src/Game/PlayGround.h

src/Game/Settings.h: src/Game/Enums.h src/Exceptions/InvalidArgumentException.h

src/Game/Worm.h: src/Game/Enums.h src/Game/Point.h

src/main.cpp: src/Exceptions/Exception.h src/Translation/TranslateEngine.h src/ViewModels/ViewModelChooser.h src/Game/NibbleGame.h

##############
##	EVENTS  ##
##############

$(TARGET_DIR)/Events.o: $(TARGET_DIR)/Single.o $(TARGET_DIR)/EventContainer.o $(TARGET_DIR)/ServerSide.o $(TARGET_DIR)/ClientSide.o
	$(LINKER) -r -o $@ $^

$(TARGET_DIR)/Single.o: src/Game/Events/Single.cpp src/Game/Events/Single.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/EventContainer.o: src/Game/Events/EventContainer.cpp src/Game/Events/EventContainer.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/ServerSide.o: src/Game/Events/ServerSide.cpp src/Game/Events/ServerSide.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/ClientSide.o: src/Game/Events/ClientSide.cpp src/Game/Events/ClientSide.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

src/Game/Events/ClientSide.h: src/Game/Events/AbstractEvent.h src/ViewModels/Abstract/AbstractInput.h src/Game/Enums.h src/Game/Settings.h src/Game/Worm.h src/Game/NetworkCommunication.h

src/Game/Events/EventContainer.h: src/Game/Events/AbstractEvent.h

src/Game/Events/ServerSide.h: src/Game/Events/AbstractEvent.h src/Game/Worm.h src/Game/PlayGround.h src/Game/PlaygroundFactory.h src/Game/NetworkCommunication.h

src/Game/Events/Single.h: src/Game/Events/AbstractEvent.h src/ViewModels/Abstract/AbstractInput.h src/Game/Worm.h src/Game/Settings.h


#############
##	TASKS  ##
#############

$(TARGET_DIR)/Tasks.o: $(TARGET_DIR)/BaseTask.o $(TARGET_DIR)/WaitingTask.o $(TARGET_DIR)/RandomAI.o $(TARGET_DIR)/BFSAI.o $(TARGET_DIR)/BaseAITask.o $(TARGET_DIR)/DiscardingInput.o $(TARGET_DIR)/ServerListener.o
	$(LINKER) -r -o $@ $^

$(TARGET_DIR)/BaseTask.o: src/Game/Tasks/BaseTask.cpp
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/WaitingTask.o: src/Game/Tasks/WaitingTask.cpp src/Game/Tasks/WaitingTask.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/BaseAITask.o: src/Game/Tasks/BaseAITask.cpp src/Game/Tasks/BaseAITask.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/RandomAI.o: src/Game/Tasks/RandomAI.cpp src/Game/Tasks/RandomAI.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/BFSAI.o: src/Game/Tasks/BFSAI.cpp src/Game/Tasks/BFSAI.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/DiscardingInput.o: src/Game/Tasks/DiscardingInput.cpp src/Game/Tasks/DiscardingInput.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/ServerListener.o: src/Game/Tasks/ServerListener.cpp src/Game/Tasks/ServerListener.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

src/Game/Tasks/BaseAITask.h: src/Game/Tasks/BaseTask.h src/Game/Worm.h src/Game/GameContent.h

src/Game/Tasks/BFSAI.h: src/Game/Tasks/BaseAITask.h src/Exceptions/InvalidArgumentException.h

src/Game/Tasks/DiscardingInput.h: src/Game/Tasks/BaseTask.h src/ViewModels/Abstract/AbstractInput.h

src/Game/Tasks/RandomAI.h: src/Game/Tasks/BaseAITask.h

src/Game/Tasks/ServerListener.h: src/Game/Tasks/BaseTask.h src/Game/Worm.h src/Game/NetworkCommunication.h

src/Game/Tasks/WaitingTask.h: src/Game/Tasks/BaseTask.h


##################
##	EXCEPTIONS  ##
##################

$(TARGET_DIR)/Exceptions.o: $(TARGET_DIR)/Exception.o $(TARGET_DIR)/InvalidArgumentException.o $(TARGET_DIR)/OutOfRangeException.o $(TARGET_DIR)/InvalidFormatException.o $(TARGET_DIR)/ServerException.o
	$(LINKER) -r -o $@ $^

$(TARGET_DIR)/InvalidArgumentException.o: src/Exceptions/InvalidArgumentException.cpp src/Exceptions/InvalidArgumentException.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/Exception.o: src/Exceptions/Exception.cpp src/Exceptions/Exception.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/OutOfRangeException.o: src/Exceptions/OutOfRangeException.cpp src/Exceptions/OutOfRangeException.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/InvalidFormatException.o: src/Exceptions/InvalidFormatException.cpp src/Exceptions/InvalidFormatException.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/ServerException.o: src/Exceptions/ServerException.cpp src/Exceptions/ServerException.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

src/Exceptions/ServerException.h: src/Exceptions/Exception.h

src/Exceptions/InvalidFormatException.h: src/Exceptions/Exception.h

src/Exceptions/OutOfRangeException.h: src/Exceptions/Exception.h

src/Exceptions/InvalidArgumentException.h: src/Exceptions/Exception.h


#################
##	TRANSLATE  ##
#################

$(TARGET_DIR)/Translate.o : $(TARGET_DIR)/TranslateEngine.o
	$(LINKER) -r -o $@ $^

$(TARGET_DIR)/TranslateEngine.o: src/Translation/TranslateEngine.cpp src/Translation/TranslateEngine.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

src/Translation/TranslateEngine.h: src/Exceptions/InvalidArgumentException.h src/Exceptions/InvalidFormatException.h

##############
##	STATES  ##
##############

$(TARGET_DIR)/States.o: $(TARGET_DIR)/GameStates.o $(TARGET_DIR)/SplashScreenGameState.o $(TARGET_DIR)/MenuGameState.o $(TARGET_DIR)/SingleplayerGameState.o $(TARGET_DIR)/PlayingState.o $(TARGET_DIR)/NetGameState.o $(TARGET_DIR)/MultiplayerGameState.o $(TARGET_DIR)/SettingsState.o $(TARGET_DIR)/EndState.o $(TARGET_DIR)/GamePauseState.o
	$(LINKER) -r -o $@ $^

$(TARGET_DIR)/GameStates.o: src/States/GameStates.cpp src/States/GameStates.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/SplashScreenGameState.o: src/States/SplashScreenGameState.cpp src/States/SplashScreenGameState.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/MenuGameState.o: src/States/MenuGameState.cpp src/States/MenuGameState.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/SingleplayerGameState.o: src/States/SingleplayerGameState.cpp src/States/SingleplayerGameState.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/PlayingState.o: src/States/PlayingState.cpp src/States/PlayingState.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/NetGameState.o: src/States/NetGameState.cpp src/States/NetGameState.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/MultiplayerGameState.o: src/States/MultiplayerGameState.cpp src/States/MultiplayerGameState.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/EndState.o: src/States/EndState.cpp src/States/EndState.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/SettingsState.o: src/States/SettingsState.cpp src/States/SettingsState.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/GamePauseState.o: src/States/GamePauseState.cpp src/States/GamePauseState.h
	$(COMPILER) -c -o $@ $< $(COMPILE_FLAGS)

src/States/AbstractGameState.h: src/States/StatesNames.h src/ViewModels/Abstract/BaseViewModel.h

src/States/EndState.h: src/States/AbstractGameState.h

src/States/GamePauseState.h: src/States/AbstractGameState.h src/ViewModels/Abstract/BaseViewModel.h

src/States/GameStates.h: src/States/AbstractGameState.h

src/States/MenuGameState.h: src/States/AbstractGameState.h src/ViewModels/Abstract/BaseViewModel.h

src/States/MultiplayerGameState.h: src/States/AbstractGameState.h

src/States/MenuGameState.h: src/States/AbstractGameState.h src/ViewModels/Abstract/NetMenuAbstractViewModel.h src/Game/Events/ServerSide.h src/Game/Events/ClientSide.h src/Game/Tasks/DiscardingInput.h src/Game/Tasks/ServerListener.h src/Game/GameContent.h src/Game/NetworkCommunication.h

src/States/PlayingState.h: src/States/AbstractGameState.h src/Game/Enums.h src/Game/GameContent.h

src/States/SettingsState.h: src/States/AbstractGameState.h src/ViewModels/Abstract/SettingsAbstractViewModel.h

src/States/SingleplayerGameState.h: src/States/AbstractGameState.h src/Game/PlaygroundFactory.h src/Game/Worm.h src/Game/GameContent.h src/Game/Events/Single.h src/Game/Tasks/WaitingTask.h src/Game/Tasks/DiscardingInput.h src/Game/AIFactory.h

src/States/SplashScreenGameState.h: src/States/AbstractGameState.h



##################
##	VIEW MODELS ##
##################
$(TARGET_DIR)/ViewModels.o: $(TARGET_DIR)/ViewModelChooser.o $(TARGET_DIR)/ConsoleModel.o $(TARGET_DIR)/SDLModel.o $(TARGET_DIR)/NCursesModel.o $(TARGET_DIR)/Translate.o $(TARGET_DIR)/BaseViewModel.o
	$(LINKER) -r -o $@ $^

$(TARGET_DIR)/ViewModelChooser.o: src/ViewModels/ViewModelChooser.cpp src/ViewModels/ViewModelChooser.h
	$(COMPILER) -o $@ -c $< $(COMPILE_FLAGS)

$(TARGET_DIR)/BaseViewModel.o: src/ViewModels/Abstract/BaseViewModel.cpp src/ViewModels/Abstract/BaseViewModel.h
	$(COMPILER) -o $@ -c $< $(COMPILE_FLAGS)


## NCURSES
$(TARGET_DIR)/NCursesModel.o: $(TARGET_DIR)/SplashScreenNCursesViewModel.o $(TARGET_DIR)/SingleplayerMenuNCursesViewModel.o $(TARGET_DIR)/ScoreNCursesViewModel.o $(TARGET_DIR)/NetMenuNCursesViewModel.o $(TARGET_DIR)/MultiplayerNCursesViewModel.o $(TARGET_DIR)/MenuNCursesViewModel.o $(TARGET_DIR)/SettingsNCursesViewModel.o $(TARGET_DIR)/GameNCursesViewModel.o $(TARGET_DIR)/NCursesViewModel.o $(TARGET_DIR)/QuitNCursesViewModel.o $(TARGET_DIR)/NCursesInput.o
	$(LINKER) -r -o $@ $^

$(TARGET_DIR)/NCursesViewModel.o: src/ViewModels/NCURSES/NCursesViewModel.cpp  src/ViewModels/NCURSES/NCursesViewModel.h src/ViewModels/NCURSES/GameNCursesViewModel.h src/ViewModels/NCURSES/SettingsNCursesViewModel.h src/ViewModels/NCURSES/MenuNCursesViewModel.h src/ViewModels/NCURSES/MultiplayerNCursesViewModel.h src/ViewModels/NCURSES/NetMenuNCursesViewModel.h src/ViewModels/NCURSES/ScoreNCursesViewModel.h src/ViewModels/NCURSES/SingleplayerMenuNCursesViewModel.h src/ViewModels/NCURSES/SplashScreenNCursesViewModel.h  src/ViewModels/NCURSES/QuitNCursesViewModel.h $(__ABSTRACTION_FILES)
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/GameNCursesViewModel.o: src/ViewModels/NCURSES/GameNCursesViewModel.cpp src/ViewModels/NCURSES/GameNCursesViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/SettingsNCursesViewModel.o: src/ViewModels/NCURSES/SettingsNCursesViewModel.cpp src/ViewModels/NCURSES/SettingsNCursesViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/MenuNCursesViewModel.o: src/ViewModels/NCURSES/MenuNCursesViewModel.cpp src/ViewModels/NCURSES/MenuNCursesViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/MultiplayerNCursesViewModel.o: src/ViewModels/NCURSES/MultiplayerNCursesViewModel.cpp src/ViewModels/NCURSES/MultiplayerNCursesViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/NetMenuNCursesViewModel.o: src/ViewModels/NCURSES/NetMenuNCursesViewModel.cpp src/ViewModels/NCURSES/NetMenuNCursesViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/ScoreNCursesViewModel.o: src/ViewModels/NCURSES/ScoreNCursesViewModel.cpp src/ViewModels/NCURSES/ScoreNCursesViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/SingleplayerMenuNCursesViewModel.o: src/ViewModels/NCURSES/SingleplayerMenuNCursesViewModel.cpp src/ViewModels/NCURSES/SingleplayerMenuNCursesViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/SplashScreenNCursesViewModel.o: src/ViewModels/NCURSES/SplashScreenNCursesViewModel.cpp src/ViewModels/NCURSES/SplashScreenNCursesViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/QuitNCursesViewModel.o: src/ViewModels/NCURSES/QuitNCursesViewModel.cpp src/ViewModels/NCURSES/QuitNCursesViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/NCursesInput.o: src/ViewModels/NCURSES/NCursesInput.cpp src/ViewModels/NCURSES/NCursesInput.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

src/ViewModels/NCURSES/NCURSESViewModel.h: src/ViewModels/Abstract/BaseViewModel.h src/ViewModels/NCURSES/SplashScreenNCursesViewModel.h src/ViewModels/NCURSES/MenuNCursesViewModel.h src/ViewModels/NCURSES/SettingsNCursesViewModel.h src/ViewModels/NCURSES/MultiplayerNCursesViewModel.h src/ViewModels/NCURSES/NetMenuNCursesViewModel.h src/ViewModels/NCURSES/SingleplayerMenuNCursesViewModel.h src/ViewModels/NCURSES/GameNCursesViewModel.h src/ViewModels/NCURSES/ScoreNCursesViewModel.h src/ViewModels/NCURSES/QuitNCursesViewModel.h src/ViewModels/NCURSES/NCursesInput.h

src/ViewModels/NCURSES/GameNCursesViewModel.h: src/ViewModels/Abstract/GameAbstractViewModel.h

src/ViewModels/NCURSES/MenuNCursesViewModel.h: src/ViewModels/Abstract/MenuAbstractViewModel.h

src/ViewModels/NCURSES/MultiplayerNCursesViewModel.h: src/ViewModels/Abstract/MultiplayerAbstractViewModel.h

src/ViewModels/NCURSES/NetMenuNCursesViewModel.h: src/ViewModels/Abstract/NetMenuAbstractViewModel.h

src/ViewModels/NCURSES/QuitNCursesViewModel.h: src/ViewModels/Abstract/QuitAbstractViewModel.h

src/ViewModels/NCURSES/ScoreNCursesViewModel.h: src/ViewModels/Abstract/ScoreAbstractViewModel.h

src/ViewModels/NCURSES/NCursesInput.h: src/ViewModels/Abstract/AbstractInput.h

src/ViewModels/NCURSES/SettingsNCursesViewModel.h: src/ViewModels/Abstract/SettingsAbstractViewModel.h

src/ViewModels/NCURSES/SingleplayerMenuNCursesViewModel.h: src/ViewModels/Abstract/SingleplayerMenuAbstractViewModel.h

src/ViewModels/NCURSES/SplashScreenNCursesViewModel.h: src/ViewModels/Abstract/SplashPauseScreenAbstractViewModel.h


## SDL
$(TARGET_DIR)/SDLModel.o: $(TARGET_DIR)/SplashScreenSDLViewModel.o $(TARGET_DIR)/SingleplayerMenuSDLViewModel.o $(TARGET_DIR)/ScoreSDLViewModel.o $(TARGET_DIR)/NetMenuSDLViewModel.o $(TARGET_DIR)/MultiplayerSDLViewModel.o $(TARGET_DIR)/MenuSDLViewModel.o $(TARGET_DIR)/SettingsSDLViewModel.o $(TARGET_DIR)/GameSDLViewModel.o $(TARGET_DIR)/SDLViewModel.o $(TARGET_DIR)/QuitSDLViewModel.o $(TARGET_DIR)/SDLInput.o
	$(LINKER) -r -o $@ $^

$(TARGET_DIR)/SDLViewModel.o: src/ViewModels/SDL/SDLViewModel.cpp  src/ViewModels/SDL/SDLViewModel.h src/ViewModels/SDL/GameSDLViewModel.h src/ViewModels/SDL/SettingsSDLViewModel.h src/ViewModels/SDL/MenuSDLViewModel.h src/ViewModels/SDL/MultiplayerSDLViewModel.h src/ViewModels/SDL/NetMenuSDLViewModel.h src/ViewModels/SDL/ScoreSDLViewModel.h src/ViewModels/SDL/SingleplayerMenuSDLViewModel.h src/ViewModels/SDL/SplashScreenSDLViewModel.h src/ViewModels/SDL/QuitSDLViewModel.h $(__ABSTRACTION_FILES)
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/GameSDLViewModel.o: src/ViewModels/SDL/GameSDLViewModel.cpp src/ViewModels/SDL/GameSDLViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/SettingsSDLViewModel.o: src/ViewModels/SDL/SettingsSDLViewModel.cpp src/ViewModels/SDL/SettingsSDLViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/MenuSDLViewModel.o: src/ViewModels/SDL/MenuSDLViewModel.cpp src/ViewModels/SDL/MenuSDLViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/MultiplayerSDLViewModel.o: src/ViewModels/SDL/MultiplayerSDLViewModel.cpp src/ViewModels/SDL/MultiplayerSDLViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/NetMenuSDLViewModel.o: src/ViewModels/SDL/NetMenuSDLViewModel.cpp src/ViewModels/SDL/NetMenuSDLViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/ScoreSDLViewModel.o: src/ViewModels/SDL/ScoreSDLViewModel.cpp src/ViewModels/SDL/ScoreSDLViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/SingleplayerMenuSDLViewModel.o: src/ViewModels/SDL/SingleplayerMenuSDLViewModel.cpp src/ViewModels/SDL/SingleplayerMenuSDLViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/SplashScreenSDLViewModel.o: src/ViewModels/SDL/SplashScreenSDLViewModel.cpp src/ViewModels/SDL/SplashScreenSDLViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/QuitSDLViewModel.o: src/ViewModels/SDL/QuitSDLViewModel.cpp src/ViewModels/SDL/QuitSDLViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/SDLInput.o: src/ViewModels/SDL/SDLInput.cpp src/ViewModels/SDL/SDLInput.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

src/ViewModels/SDL/SDLViewModel.h: src/ViewModels/Abstract/BaseViewModel.h src/ViewModels/SDL/SplashScreenSDLViewModel.h src/ViewModels/SDL/SingleplayerMenuSDLViewModel.h src/ViewModels/SDL/SDLInput.h src/ViewModels/SDL/ScoreSDLViewModel.h src/ViewModels/SDL/QuitSDLViewModel.h src/ViewModels/SDL/NetMenuSDLViewModel.h src/ViewModels/SDL/MultiplayerSDLViewModel.h src/ViewModels/SDL/MenuSDLViewModel.h src/ViewModels/SDL/SettingsSDLViewModel.h src/ViewModels/SDL/GameSDLViewModel.h

src/ViewModels/SDL/GameSDLViewModel.h: src/ViewModels/Abstract/GameAbstractViewModel.h

src/ViewModels/SDL/MenuSDLViewModel.h: src/ViewModels/Abstract/MenuAbstractViewModel.h

src/ViewModels/SDL/MultiplayerSDLViewModel.h: src/ViewModels/Abstract/MultiplayerAbstractViewModel.h

src/ViewModels/SDL/NetMenuSDLViewModel.h: src/ViewModels/Abstract/NetMenuAbstractViewModel.h

src/ViewModels/SDL/QuitSDLViewModel.h: src/ViewModels/Abstract/QuitAbstractViewModel.h

src/ViewModels/SDL/ScoreSDLViewModel.h: src/ViewModels/Abstract/ScoreAbstractViewModel.h

src/ViewModels/SDL/SDLInput.h: src/ViewModels/Abstract/AbstractInput.h

src/ViewModels/SDL/SettingsSDLViewModel.h: src/ViewModels/Abstract/SettingsAbstractViewModel.h

src/ViewModels/SDL/SingleplayerMenuSDLViewModel.h: src/ViewModels/Abstract/SingleplayerMenuAbstractViewModel.h

src/ViewModels/SDL/SplashScreenSDLViewModel.h: src/ViewModels/Abstract/SplashPauseScreenAbstractViewModel.h


## CONSOLE
$(TARGET_DIR)/ConsoleModel.o: $(TARGET_DIR)/SplashPauseScreenConsoleViewModel.o $(TARGET_DIR)/SingleplayerMenuConsoleViewModel.o $(TARGET_DIR)/ScoreConsoleViewModel.o $(TARGET_DIR)/NetMenuConsoleViewModel.o $(TARGET_DIR)/MultiplayerConsoleViewModel.o $(TARGET_DIR)/MenuConsoleViewModel.o $(TARGET_DIR)/SettingsConsoleViewModel.o $(TARGET_DIR)/GameConsoleViewModel.o $(TARGET_DIR)/ConsoleViewModel.o $(TARGET_DIR)/QuitConsoleViewModel.o $(TARGET_DIR)/ConsoleInput.o
	$(LINKER) -r -o $@ $^

$(TARGET_DIR)/ConsoleViewModel.o: src/ViewModels/CONSOLE/ConsoleViewModel.cpp  src/ViewModels/CONSOLE/ConsoleViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/GameConsoleViewModel.o: src/ViewModels/CONSOLE/GameConsoleViewModel.cpp src/ViewModels/CONSOLE/GameConsoleViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/SettingsConsoleViewModel.o: src/ViewModels/CONSOLE/SettingsConsoleViewModel.cpp src/ViewModels/CONSOLE/SettingsConsoleViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/MenuConsoleViewModel.o: src/ViewModels/CONSOLE/MenuConsoleViewModel.cpp src/ViewModels/CONSOLE/MenuConsoleViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/MultiplayerConsoleViewModel.o: src/ViewModels/CONSOLE/MultiplayerConsoleViewModel.cpp src/ViewModels/CONSOLE/MultiplayerConsoleViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/NetMenuConsoleViewModel.o: src/ViewModels/CONSOLE/NetMenuConsoleViewModel.cpp src/ViewModels/CONSOLE/NetMenuConsoleViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/ScoreConsoleViewModel.o: src/ViewModels/CONSOLE/ScoreConsoleViewModel.cpp src/ViewModels/CONSOLE/ScoreConsoleViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/SingleplayerMenuConsoleViewModel.o: src/ViewModels/CONSOLE/SingleplayerMenuConsoleViewModel.cpp src/ViewModels/CONSOLE/SingleplayerMenuConsoleViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/SplashPauseScreenConsoleViewModel.o: src/ViewModels/CONSOLE/SplashPauseScreenConsoleViewModel.cpp src/ViewModels/CONSOLE/SplashPauseScreenConsoleViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/QuitConsoleViewModel.o: src/ViewModels/CONSOLE/QuitConsoleViewModel.cpp src/ViewModels/CONSOLE/QuitConsoleViewModel.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

$(TARGET_DIR)/ConsoleInput.o: src/ViewModels/CONSOLE/ConsoleInput.cpp src/ViewModels/CONSOLE/ConsoleInput.h
	g++ -c -o $@ $< $(COMPILE_FLAGS)

src/ViewModels/CONSOLE/ConsoleViewModel.h: src/ViewModels/Abstract/BaseViewModel.h src/ViewModels/CONSOLE/SplashPauseScreenConsoleViewModel.h src/ViewModels/CONSOLE/MenuConsoleViewModel.h src/ViewModels/CONSOLE/SettingsConsoleViewModel.h src/ViewModels/CONSOLE/MultiplayerConsoleViewModel.h src/ViewModels/CONSOLE/NetMenuConsoleViewModel.h src/ViewModels/CONSOLE/SingleplayerMenuConsoleViewModel.h src/ViewModels/CONSOLE/GameConsoleViewModel.h src/ViewModels/CONSOLE/ScoreConsoleViewModel.h src/ViewModels/CONSOLE/QuitConsoleViewModel.h src/ViewModels/CONSOLE/ConsoleInput.h

src/ViewModels/CONSOLE/ConsoleInput.h: src/ViewModels/Abstract/AbstractInput.h src/Exceptions/Exception.h

src/ViewModels/CONSOLE/GameConsoleViewModel.h: src/ViewModels/Abstract/GameAbstractViewModel.h

src/ViewModels/CONSOLE/MenuConsoleViewModel.h: src/ViewModels/Abstract/MenuAbstractViewModel.h

src/ViewModels/CONSOLE/MultiplayerConsoleViewModel.h: src/ViewModels/Abstract/MultiplayerAbstractViewModel.h src/Game/PlaygroundFactory.h

src/ViewModels/CONSOLE/NetMenuConsoleViewModel.h: src/ViewModels/Abstract/NetMenuAbstractViewModel.h src/Game/PlaygroundFactory.h

src/ViewModels/CONSOLE/QuitConsoleViewModel.h: src/ViewModels/Abstract/QuitAbstractViewModel.h

src/ViewModels/CONSOLE/ScoreConsoleViewModel.h: src/ViewModels/Abstract/ScoreAbstractViewModel.h

src/ViewModels/CONSOLE/SettingsConsoleViewModel.h: src/ViewModels/Abstract/SettingsAbstractViewModel.h

src/ViewModels/CONSOLE/SingleplayerMenuConsoleViewModel.h: src/ViewModels/Abstract/SingleplayerMenuAbstractViewModel.h src/Game/PlaygroundFactory.h

src/ViewModels/CONSOLE/SplashPauseScreenConsoleViewModel.h: src/ViewModels/Abstract/SplashPauseScreenAbstractViewModel.h


## ABSTRACT
src/ViewModels/Abstract/AbstractInput.h: src/Game/Enums.h

src/ViewModels/Abstract/BaseViewModel.h: src/Translation/TranslateEngine.h src/ViewModels/Abstract/SplashPauseScreenAbstractViewModel.h src/ViewModels/Abstract/MenuAbstractViewModel.h src/ViewModels/Abstract/SettingsAbstractViewModel.h src/ViewModels/Abstract/MultiplayerAbstractViewModel.h src/ViewModels/Abstract/NetMenuAbstractViewModel.h src/ViewModels/Abstract/SingleplayerMenuAbstractViewModel.h src/ViewModels/Abstract/GameAbstractViewModel.h src/ViewModels/Abstract/ScoreAbstractViewModel.h src/ViewModels/Abstract/QuitAbstractViewModel.h src/ViewModels/Abstract/AbstractInput.h

src/ViewModels/Abstract/GameAbstractViewModel.h: src/ViewModels/Abstract/ViewModelDerivatingClass.h src/Game/GameContent.h

src/ViewModels/Abstract/MenuAbstractViewModel.h: src/ViewModels/Abstract/ViewModelDerivatingClass.h

src/ViewModels/Abstract/MultiplayerAbstractViewModel.h: src/ViewModels/Abstract/ViewModelDerivatingClass.h

src/ViewModels/Abstract/NetMenuAbstractViewModel.h: src/ViewModels/Abstract/ViewModelDerivatingClass.h

src/ViewModels/Abstract/QuitAbstractViewModel.h: src/ViewModels/Abstract/ViewModelDerivatingClass.h

src/ViewModels/Abstract/ScoreAbstractViewModel.h: src/ViewModels/Abstract/ViewModelDerivatingClass.h

src/ViewModels/Abstract/SettingsAbstractViewModel.h: src/ViewModels/Abstract/ViewModelDerivatingClass.h src/Game/Settings.h

src/ViewModels/Abstract/SingleplayerMenuAbstractViewModel.h: src/ViewModels/Abstract/ViewModelDerivatingClass.h

src/ViewModels/Abstract/SplashPauseScreenAbstractViewModel.h: src/ViewModels/Abstract/ViewModelDerivatingClass.h src/Game/Worm.h src/ViewModels/CONSOLE/ConsoleInput.h

src/ViewModels/Abstract/ViewModelDerivatingClass.h: src/Translation/TranslateEngine.h