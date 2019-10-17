#include "pch.h"
#include "Game.h"


CommandList Game::mainMenuCommands;
CommandList Game::gameCommands;

// the current menu to draw and the commands to go with them
CommandList* Game::currentCommands;
function<void(Pet&)> Game::currentMenu;
Pet* Game::currentPet;

int Game::actionCount;	// how many action have user preformed?


// ## UTILITY METHODS ##

// how many days have gone by
int Game::GetDayCount()
{
	return actionCount / 2 + 1;
}

// how many action have user preformed today?
int Game::GetActionCountToday()
{
	return actionCount % 2 + 1;
}

// starts game and asks for dog name
void Game::StartGame()
{
	// starts a new game, creates a new pet with user input
	SetGameMenu();
	currentPet = new Pet();
	actionCount = 0;
	UI::Write("New pet created");
	UI::Write("Please enter a name for your pet");
	currentPet->m_name = UserInput::String();
}

// closes the application
void Game::ExitGame()
{
	exit(0);
}

// initialize the game's commands
void Game::InitializeCommands()
{
	// creates commands that will occur in main menu
	mainMenuCommands = CommandList();
	mainMenuCommands.Add("start", StartGame);
	mainMenuCommands.Add("quit", ExitGame);


	/// a callback after a command is done on the game's screen
	gameCommands = CommandList(GameCommandCallback);

	// game commands (actions to do with pet)
	gameCommands.Add("feed", [](){
		Game::currentPet->Feed();
		UI::Write("Yum yum yum yum, thanks!");
	});
	gameCommands.Add("water", [](){
		Game::currentPet->Water();
		UI::Write("Gulp gulp gulp, thanks!"); 
	});
	gameCommands.Add("walk", [](){
		Game::currentPet->Walk();
		UI::Write("Trot trot trot trot, phew!");
	});
	gameCommands.Add("play", [](){
		Game::currentPet->Play();
		UI::Write("Phew that was a lot of fun!");
	});
	gameCommands.Add("nap", [](){
		Game::currentPet->Nap();
		UI::Write("Yawn! What a perfect nap!");
	});
	gameCommands.Add("cuddle", [](){
		Game::currentPet->Cuddle();
		UI::Write("Aww thanks!");
	});
}

void Game::SetMainMenu()
{
	currentMenu = UI::MainMenu;
	currentCommands = &mainMenuCommands;
}

void Game::SetGameMenu()
{
	currentMenu = UI::GameMenu;
	currentCommands = &gameCommands;
}

// Called after user enters a command in the game menu
void Game::GameCommandCallback(bool success)
{
	if (!success)
		return; /// exits if command failed
	actionCount++; /// tracks how many choices made

	// pet will sleep for 1 day if neglegted
	if (currentPet->m_energy < 8)
	{
		UI::WriteBad("Your pet is out of energy and must sleep for a day!");
		currentPet->EndOfDayUpdate();
		actionCount += 2; // move 1 day
	}

	list<string> problemList;
	currentPet->ForEachStat([&problemList](PetStat stat) {
		if (4 < stat.m_value)
		{
			// if at a dangerous level, warn user
			if (stat.m_value < 64)
				UI::Tip("You're pet needs you to maintain it's \"" + *stat.m_name + "\"");

			return; /// if none of the stats are before 4, pet stays
		}

		currentPet->m_atHome = false;
		problemList.push_back("You failed to maintain the pet's \"" + *stat.m_name + "\"");
	});

	// if pet ran away start user over
	if (!currentPet->m_atHome)
	{
		// shows fail message and reasons why user failed
		UI::WriteBad("You failed to keep your pet in good health and they ran away!");
		for (string problem : problemList)
			UI::Tip(problem); /// writes all problems out

		UI::Write("Do you want to get another pet?");

		if (UserInput::YesNo())
			SetMainMenu();  /// brings user back to main menu if they want to play again
		else
			ExitGame(); /// exits otherwise
		return;
	}

	// after each action, progress time
	if (actionCount % 2 == 0)
	{
		currentPet->EndOfDayUpdate();
		UI::Write("Press any key to progress to next day...");
	}
	else
	{
		currentPet->MidDayUpdate();
		UI::Write("Press any key to progress to end of day...");
	}

	UserInput::WaitForKey();
}