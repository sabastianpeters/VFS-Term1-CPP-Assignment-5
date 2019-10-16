#pragma once 

#include <functional>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

class CommandList final /// final so can't be inherited
{
private:

	// ## Private Members ##

	function<void(bool)> m_callback;			// callback for after a command call is made
	map<string, function<void()>> m_dictionary;	// dictionary of commands

public:

	// ## Constructors & Deconstructor ##

	CommandList();
	CommandList(function<void(bool)> callback);	 // command constructor with callback (passes if command was sucessful)

	~CommandList();


	// ## Methods ##

	bool Call(string commandName);							// tries to call a function and returns if successful
	void Add(string commandName, function<void()> action);	// adds command to list
	void ForEach(function<void(string, function<void()>)> action);	// preforms an action with each command <commandName, commandAction>
	
};

