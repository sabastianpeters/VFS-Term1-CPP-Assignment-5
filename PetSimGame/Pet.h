#pragma once

#include "PetStat.h"
#include <string>
#include <functional>


class Pet
{
private:
	vector<PetStat*> m_statList;

public:

	// ## Members ##

	PetStat m_hunger;	// how hungry pet is
	PetStat m_thirst;	// how thirsty pet is
	PetStat m_comfort;	// how comfortable pet it
	PetStat m_energy;	// energy of the pet
	PetStat m_satisfaction; // how happy is the pet?
	string m_name;		// name of the pet
	bool m_atHome;		// has the pet run away yet


	// ## Constructor and Destructor ##

	Pet();

	~Pet();


	// ## Methods ##

	void ForEachStat(function<void(PetStat&)>);	// performs an action with each stat

	void Feed();	// feed pet
	void Water();	// give pet water
	void Walk();	// walk pet
	void Play();	// play with pet
	void Nap();		// let pet name
	void Cuddle();	// cuddle the pet

	void MidDayUpdate();	// update stats based on mid day
	void EndOfDayUpdate();	// update stats based on end of day

private:

	// ## Private Tag List Reference ##

	const static vector<string> hungerStatTagList;
	const static vector<string> thirstStatTagList;
	const static vector<string> comfortStatTagList;
	const static vector<string> energyStatTagList;
	const static vector<string> satisfactionStatTagList;
};

