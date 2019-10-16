#pragma once
#include "CommandList.h"
#include "UserInput.h"
#include "Pet.h"
#include "UI.h"
#include <list>
using namespace std;


class Game
{
public:
	
	// ## Members ##
	
	// Command Lists
	static CommandList mainMenuCommands;
	static CommandList gameCommands;

	// the current menu to draw and the commands to go with them
	static CommandList currentCommands;
	static function<void(Pet&)> currentMenu;
	static Pet currentPet;

	static int actionCount;	// how many action have user preformed?


	// ## Constructor and Destructor ##
	Game() =delete;
	~Game() = delete;


	// ## Utility Methods ##
	
	static int GetDayCount();			// how many days have gone by
	static int GetActionCountToday();	// how many action have user preformed today?

	static void StartGame();			// starts game and asks for dog name
	static void ExitGame();				// closes the application
	static void InitializeCommands();	// initialize the game's commands

	static void SetMainMenu();
	static void SetGameMenu();

	static void GameCommandCallback(bool success); // Called after user enters a command in the game menu

};

