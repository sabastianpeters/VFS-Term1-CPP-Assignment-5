#pragma once
#include <string>
#include "Colors.h"
#include "Pet.h"
#include "PetStat.h"
#include "CommandList.h"
#include "StringFormatting.h"
#include <iostream>
using namespace std;

// NOTE: For this file i gave most methods' params no names (thinking this
// would allow me to call it what I want. Turns out I can still call it whatever
// I want, and leaving nothing there reduces readability. In future I would name
// params. For lack of time (2:47a now), I will leave as is

class UI
{
private:

	// ## Private Utility Members ##

	static const int STAT_NAME_LENGTH;		// How many chars long should stat name be drawn to?
	static const string DIVISION_STRING;	// Reference to a string that devides sections of console

public:



	// ## Constructor & Deconstructor ## // Removes constructor & deconstructor (only want static)

	UI() =delete;
	~UI() =delete;

	// ## MENUs ##

	static void MainMenu(Pet &pet); // draws main menu
	static void GameMenu(Pet &pet); // draws game

	// ## USER INPUT & CONSOLE OUTPUT ##

	static string Read();					// Gets and returns input from user
	static void Write(const string&, ForegroundColor, BackgroundColor); // Used for talking to user (custom colors)
	static void Write(const string&);		// Used for talking to user
	static void WriteBad(const string&);	// Used for teling bad info to user
	static void Tip(const string&);			// Used for logging tip information to user
	static void Error(const string&);		// Used for logging user errors (typically input errors)
	static void Debug(const string&);		// Used for logging debug info
	static void DrawCommands(CommandList); // Logs Commands from command list

private: 

	// ## UTILITY DRAWING TOOLS ##
	static void _DrawHeader(string);				// Draws a header with given text
	static void _DrawStatBar(const PetStat &);		// Draws stat bar with provided bar info
	static ForegroundColor _DetermineBarColor(int);	// Determines color of stat bar based on value
};

