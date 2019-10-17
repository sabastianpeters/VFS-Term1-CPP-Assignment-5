#include "pch.h"
#include "Pet.h"	


const vector<string> Pet::hungerStatTagList {
	"Stuffed",
	"Full",
	"Peckish",
	"Hungry",
	"Starving"
};

const vector<string> Pet::thirstStatTagList {
	"Sated",
	"Quenched",
	"Thirsty",
	"Parched",
	"Dehydrated"
};

const vector<string> Pet::comfortStatTagList {
	"Floating",
	"Comfortable",
	"Unbothered",
	"Uncomfortable",
	"Restless"
};

const vector<string> Pet::energyStatTagList {
	"Hyper",
	"Energetic",
	"Relaxed",
	"Tired",
	"Exausted"
};

const vector<string> Pet::satisfactionStatTagList {
	"Overjoyed",
	"Happy",
	"Content",
	"Disheartened",
	"Anguished"
};


Pet::Pet()
{
	m_atHome = true;

	m_hunger = PetStat("Hunger", hungerStatTagList);
	m_thirst = PetStat("Thirst", thirstStatTagList);
	m_comfort = PetStat("Comfort", comfortStatTagList);
	m_energy = PetStat("Energy", energyStatTagList);
	m_satisfaction = PetStat("Satisfaction", satisfactionStatTagList);

	m_statList = vector<PetStat*>();
	m_statList.push_back(&m_hunger);
	m_statList.push_back(&m_thirst);
	m_statList.push_back(&m_comfort);
	m_statList.push_back(&m_energy);
	m_statList.push_back(&m_satisfaction);
}


Pet::~Pet()
{
}

// performs an action with each stat
void Pet::ForEachStat(function<void(PetStat&)> action)
{
	for(auto it = m_statList.begin(); it != m_statList.end(); ++it) /// iterates over stats
		action(**it); /// passes current stat to action
}

void Pet::Feed()
{
	m_hunger = m_hunger + 32;
	m_thirst = m_thirst - 16;
	m_comfort = m_comfort - 16;
	m_energy = m_energy + 8;
	m_satisfaction = m_satisfaction + 8;
}

void Pet::Water()
{
	m_thirst = m_thirst + 64;
	m_energy = m_energy + 4;
	m_comfort = m_comfort - 16;
	m_satisfaction = m_satisfaction + 8;
}

void Pet::Walk()
{
	m_energy = m_energy - 16;
	m_comfort = m_comfort - 16;
	m_satisfaction = m_satisfaction + 32;
}

void Pet::Play()
{
	m_hunger = m_hunger - 16;
	m_energy = m_energy - 64;
	m_comfort = m_comfort - 16;
	m_satisfaction = m_satisfaction + 64;
}

void Pet::Nap()
{
	m_hunger = m_hunger - 16;
	m_thirst = m_thirst - 16;
	m_energy = m_energy + 64;
	m_comfort = m_comfort + 16;
	m_satisfaction = m_satisfaction + 32;
}

void Pet::Cuddle()
{
	m_comfort = m_comfort + 64;
	m_satisfaction = m_satisfaction + 64;
	m_energy = m_energy - 8;
}

void Pet::MidDayUpdate()
{
	m_hunger = m_hunger - 8;
	m_thirst = m_thirst - 8;
	m_comfort = m_comfort - 8;
	m_energy = m_energy - 8;
	m_satisfaction = m_satisfaction - 8;
}

void Pet::EndOfDayUpdate()
{
	m_hunger = m_hunger - 16;
	m_thirst = m_thirst - 16;
	m_comfort = m_comfort - 16;
	m_energy = m_energy - 8;
	m_satisfaction = m_satisfaction - 32;
}
