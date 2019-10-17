#pragma once
#include "UI.h"
#include "CommandList.h"
#include "StringFormatting.h"
#include <string>
#include <functional>
#include "conio.h"
using namespace std;

class UserInput
{
private:

	// ## Private Utility Members ##

	static const string DEFAULT_RETRY_MESSAGE;	// messaged thats displayed when wrong value entered
	static const string ERROR_PREFIX;			// prefix for the error message

public:


	// ## Constructor & Deconstructor ## // Removes constructor & deconstructor (only want static)

	UserInput() = delete;
	~UserInput() = delete;


	// ## Methods ##

	static string String();																// Gets string input
	static void Custom(string retryMessage, function<bool(string&)> predicate);			// Gets a input from user that conforms to predicate. Set value inside of predicate
	static int IntRange(int min, int max, string retryMessage = DEFAULT_RETRY_MESSAGE);	// Returns a valid int input from user within a range (inclusive)
	static int Int(string retryMessage = DEFAULT_RETRY_MESSAGE);						// Returns a valid int input from user
	static float FloatRange(float min, float max, string retryMessage = DEFAULT_RETRY_MESSAGE);	// Returns a valid float input from user within a range (inclusive)
	static float Float(string retryMessage = DEFAULT_RETRY_MESSAGE);							// Returns a valid float input from user
	static bool YesNo(string retryMessage = DEFAULT_RETRY_MESSAGE);								// Returns boolean yes / no answer from user
	static void Command(CommandList commandList, string retryMessage = "Unknown command");		// Gets a command from user
	static void WaitForKey();	// hangs program until key press
};

