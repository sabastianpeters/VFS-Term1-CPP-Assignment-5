#include "pch.h"
#include "CommandList.h"
#include <functional>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;



// command constructor with callback (passes if command was sucessful)
CommandList::CommandList() : CommandList([](bool success) {}) {} /// if no callback provided, an empty one is assigned
CommandList::CommandList(function<void(bool)> callback)
{
	m_callback = callback; /// sets callback
	m_dictionary = {};	/// empty map
}


// deconstructor
CommandList::~CommandList() {}

// tries to call a function and returns if successful
bool CommandList::Call(string commandName)
{
	// searches for a command with the given name
	map<string, function<void()>>::iterator it = m_dictionary.find(commandName);

	// return callback false if command not found
	if (it == m_dictionary.end())
	{
		m_callback(false);
		return false;
	}

	// return callback true and call command if found
	it->second(); /// calls the command action
	m_callback(true);
	return true;
}

// adds command to list
void CommandList::Add(string commandName, function<void()> action)
{
	m_dictionary.insert(pair<string, function<void()>>(commandName, action));
}

// preforms an action with each command <commandName, commandAction>
void CommandList::ForEach(function<void(string, function<void()>)> action)
{
	map<string, function<void()>>::iterator it = m_dictionary.begin();
	while (it != m_dictionary.end())
	{
		action(it->first, it->second); /// performs the action with current key-value pair
		it++; /// moves the iterator
	}
}
