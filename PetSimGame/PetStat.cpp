#include "pch.h"
#include "PetStat.h"



PetStat::PetStat(string name, const vector<string> &tagList)
{
	m_name = new string(name);
	m_tagList = &tagList;
}


PetStat::~PetStat()
{
}

// returns the current tag based on value
string PetStat::GetTag() const
{
	// Turns the value into pecentage and gets index
	int tagListSize = m_tagList->size();
	int tagIndex = (int)(tagListSize * (m_value / 256.0f));
	tagIndex = tagListSize - tagIndex - 1; /// inverts tag, positive is start, not end
	return m_tagList->at(tagIndex); /// returns value at index
}

// implicit cast to integer
PetStat::operator int() const
{
	return m_value;
}

// addition operator (friend so private members can be access in definition)
PetStat operator+(PetStat &stat, int const &i)
{
	stat.m_value += i;
	if (stat.m_value < 0)
		stat.m_value = 0;
	if (255 < stat.m_value)
		stat.m_value = 255;
	return stat; /// returns stat to be used again
}

// subtraction operator (friend so private members can be access in definition)
PetStat operator-(PetStat &stat, int const &i)
{
	return stat + (-i);
}
