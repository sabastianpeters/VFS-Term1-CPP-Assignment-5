#pragma once
#include <vector>
#include <string>
using namespace std;

class PetStat
{
public:

	// ## Members ##

	int m_value = 176;			// current value of bar // automatically starts stat off at ~70% stats (11/16 bars)
	const string* m_name;				// name of stat to display
	const vector<string>* m_tagList;	// various tags of display


	// ## Constructors & Deconstructors ##

	PetStat() =delete;
	PetStat(string &name, vector<string> &tags);

	~PetStat();


	// ## Methods ##

	string GetTag() const; // returns the current tag based on value


	// ## Operator Overloads ##

	operator int() const;								// implicit cast to integer
	friend PetStat operator + (PetStat &, int const &);	// addition operator (friend so private members can be access in definition)
	friend PetStat operator - (PetStat &, int const &);	// subraction operator (friend so private members can be access in definition)
};	

