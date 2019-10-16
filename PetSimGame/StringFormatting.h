#pragma once
#include <string>
using namespace std;


string string_pad_left(string str, unsigned int count)
{
	string _str(str);
	_str.insert(_str.begin(), count - _str.length(), ' ');
	return _str;
}

string string_pad_right(string str, unsigned int count)
{
	return str.append(count - str.length(), ' ');
}

void string_to_lower(string & str)
{
	transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); }); /// thank you https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
}

void string_to_upper(string & str)
{
	transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return toupper(c); });
}