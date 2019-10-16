#pragma once
#include <string>
using namespace std;

// ANSI COLOR CODES: https://en.wikipedia.org/wiki/ANSI_escape_code

enum class ForegroundColor : unsigned int
{
	Black = 30,
	DarkGray = 90,
	LightGray = 37,
	White = 97,
	Red = 31,
	Green = 32,
	Yellow = 33,
	Blue = 34,
	Magenta = 35,
	Cyan = 36,
	BrightRed = 91,
	BrightGreen = 92,
	BrightYellow = 93,
	BrightBlue = 94,
	BrightMagenta = 95,
	BrightCyan = 96
};

enum class BackgroundColor : unsigned int
{
	Black = 40,
	DarkGray = 100,
	LightGray = 47,
	White = 107,
	Red = 41,
	Green = 42,
	Yellow = 43,
	Blue = 44,
	Magenta = 45,
	Cyan = 46,
	BrightRed = 101,
	BrightGreen = 102,
	BrightYellow = 103,
	BrightBlue = 104,
	BrightMagenta = 105,
	BrightCyan = 106
};