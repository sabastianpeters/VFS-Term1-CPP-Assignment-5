#include "pch.h"
#include "UserInput.h"


const string UserInput::DEFAULT_RETRY_MESSAGE = "Please enter a valid value";
const string UserInput::ERROR_PREFIX = "Invalid input";


// gets string input
string UserInput::String()
{
	return string();
}

// Gets a input from user that conforms to predicate. Set value inside of predicate
void UserInput::Custom(string retryMessage, function<bool(string&)> mutable predicate)
{
	// Stays in a loop until the user enters a valid input
	while (true)
	{
		string input = UI::Read();

		if (predicate(input)) // if valid input allow
			break;
		else
			UI::Write(retryMessage); // displays an error message
	}
}

// Returns a valid int input from user within a range (inclusive)
int UserInput::IntRange(int min, int max, string retryMessage)
{
	int intInput = 0;

	// In a scenario where performance is more important, using a private
	// method instead of a lambda would be much smarter. Since I'm short
	// on time (already late - 12:28a) I left it like this.

	// Lambda Breakdown (not just copy-paste this time!! haha):
		// [&, intInput, min, max]		// capture clause - allows access to local variables, all by reference (= is by value)
		// (string & stringInput)		// parameters - passed in by caller
		// mutable						// allows me to modify captured local variables
		// { ... }						// contents of the lambda

	// gets the user input
	UserInput::Custom(retryMessage, [&, intInput, min, max](string & stringInput) mutable {

		// If cannot be parsed to int, log error
		try
		{
			intInput = stoi(stringInput);
		}
		catch (...)
		{
			UI::Error("Not a valid int");
			return false;
		}

		// If out of range, log error
		if (intInput < min)
		{
			UI::Error("Value cannot be lower than " + to_string(min));
			return false;
		}
		else if (intInput > max)
		{
			UI::Error("Value cannot be larger than " + to_string(max));
			return false;
		}

		// if no fail cases, accept value
		return true;
	});

	return intInput;
}

// Returns a valid int input from user
int UserInput::Int(string retryMessage)
{
	return UserInput::IntRange(numeric_limits<int>::min(), numeric_limits<int>::max(), retryMessage);
}

// Returns a valid float input from user within a range (inclusive)
float UserInput::FloatRange(float min, float max, string retryMessage)
{
	float floatInput = 0;

	// gets the user input
	UserInput::Custom(retryMessage, [&, floatInput, min, max](string & stringInput) mutable {

		// If cannot be parsed to int, log error
		try
		{
			floatInput = stof(stringInput);
		}
		catch (...)
		{
			UI::Error("Not a valid int");
			return false;
		}

		// If out of range, log error
		if (floatInput < min)
		{
			UI::Error("Value cannot be lower than " + to_string(min));
			return false;
		}
		else if (floatInput > max)
		{
			UI::Error("Value cannot be larger than " + to_string(max));
			return false;
		}

		// if no fail cases, accept value
		return true;
	});

	return floatInput;
}

// Returns a valid float input from user
float UserInput::Float(string retryMessage)
{
	return FloatRange(numeric_limits<float>::min(), numeric_limits<float>::max(), retryMessage);
}

// Returns boolean yes / no answer from user
bool UserInput::YesNo(string retryMessage)
{
	bool boolValue = false;

	UserInput::Custom(retryMessage, [&, boolValue](string & stringInput) mutable {

		// compares all in lowercase so case doesn't matter
		string_to_lower(stringInput);

		if (stringInput == "yes" || stringInput == "y" || stringInput == "1")
		{
			boolValue = true;
			return true; /// valid input
		}
		else if (stringInput == "no" || stringInput == "n" || stringInput == "0")
		{
			boolValue = false;
			return true; /// valid input
		}

		// by default, invalid input
		return false;
	});

	return boolValue;
}

// Gets a command from user
void UserInput::Command(CommandList commandList, string retryMessage)
{
	UserInput::Custom(retryMessage, [&commandList](string & stringInput) mutable { /// here &commandList captures just commandList as a reference (if there were other captured variables)

		// compares all in lowercase so case doesn't matter
		string_to_lower(stringInput);

		// Tries to call command, returns if successful
		return commandList.Call(stringInput); /// true if successful, and will stop asking user
	});
	
}
