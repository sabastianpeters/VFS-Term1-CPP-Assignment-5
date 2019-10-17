// PetSimGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once

#include "pch.h"
#include "Game.h"
#include "UserInput.h"
#include <iostream>

// Reguired to get a handle of console output and enable colors
#include "Windows.h"
#include "ProcessEnv.h"

using namespace std;




// ## MENU SETTERS ##
// Note: this could be done better with a menu manager and classes (avoid copy-paste)




int main()
{
	// Enables colors (virtual_terminal processing) does this
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	Game::InitializeCommands();
	Game::SetMainMenu();

	while (true)
	{
		system("CLS");
		Game::currentMenu(*Game::currentPet);
		UI::DrawCommands(*Game::currentCommands);
		UserInput::Command(*Game::currentCommands);
	}
}
