// PetSimGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once

#include "pch.h"
#include <iostream>

// Reguired to get a handle of console output and enable colors
#include "Windows.h"
#include "ProcessEnv.h"



int main()
{
	// Enables colors (virtual_terminal processing) does this
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
