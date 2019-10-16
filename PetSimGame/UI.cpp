#include "pch.h"
#include "Game.h"
#include <functional>
#include "UI.h"


const int UI::STAT_NAME_LENGTH = 14;
const string UI::DIVISION_STRING(52, '='); /// bar 52 "=" wide;


// ## MENUS ##

// draws main menu
void UI::MainMenu(Pet &pet)
{
	_DrawHeader("\u001b[0mthe world's greatest pet sim");
}


// draws game
void UI::GameMenu(Pet &pet)
{
	_DrawHeader("Your pet \"" + pet.m_name + "\" | Days: "+to_string(Game::GetDayCount())+" | "+ to_string(Game::GetActionCountToday()) +"/2 Actions");
}





// ## USER INPUT & CONSOLE OUTPUT ##

// Gets and returns input from user
string UI::Read()
{
	string input;
	cout << "\u001b[" << (int)ForegroundColor::BrightCyan << "m";
	getline(cin, input);
	return input;
}

// Used for talking to user with color (no new line)
void UI::Write(const string &str, ForegroundColor fgColor, BackgroundColor bgColor)
{
	cout << "\u001b[" << (int)bgColor << ":" << (int)fgColor << "m";
}

// Used for talking to user
void UI::Write(const string &str)
{
	Write('\n' + str, ForegroundColor::White, BackgroundColor::Black);
}

// Used for teling bad info to user
void UI::WriteBad(const string &str)
{
	Write('\n' + str, ForegroundColor::Red, BackgroundColor::Black);
}

// Used for logging tip information to user
void UI::Tip(const string &str)
{
	Write(str, ForegroundColor::DarkGray, BackgroundColor::Black);
}

// Used for logging user errors (typically input errors)
void UI::Error(const string &str)
{
	Write(str, ForegroundColor::DarkGray, BackgroundColor::Black);
}

// Used for logging debug info
void UI::Debug(const string &str)
{
	Write(str, ForegroundColor::Red, BackgroundColor::Black);
}

// Logs Commands from command list
void UI::DrawCommands(CommandList commandList)
{
	string str = "Available Actions:";
	commandList.ForEach([&str](string commandName, function<void()> action) {
		str += "   ";
		str += commandName;
	});
	Tip(str);
}





// ## UTILITY DRAWING TOOLS ##

// Draws a header with given text
void UI::_DrawHeader(string header)
{	
	string_to_upper(header);
	cout <<
		DIVISION_STRING << endl <<
		header << endl <<
		DIVISION_STRING << endl;
}

// Draws stat bar with provided bar info
void UI::_DrawStatBar(const PetStat &stat)
{
	int barValue = stat.m_value / 16;
	cout << 
		string_pad_left(*stat.m_name, STAT_NAME_LENGTH) << ": |" <<			// Draws stat name
		"\u001b[" << (int)_DetermineBarColor(barValue) << "m" << 			// Sets color for bar
		string_pad_right(string(barValue, '■'), 15) << "\u001b[0m| [" <<	// Draws bar
		stat.GetTag() << "]" << endl;										// Draws stat tag
}

// Determines color of stat bar based on value
ForegroundColor UI::_DetermineBarColor(int value)
{
	if (value <= 1)
		return ForegroundColor::Magenta;
	if (value <= 4)
		return ForegroundColor::Red;
	if (value <= 7)
		return ForegroundColor::BrightRed;
	if (value <= 10)
		return ForegroundColor::BrightYellow;
	return ForegroundColor::BrightGreen;
}

