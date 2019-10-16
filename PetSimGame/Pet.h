#pragma once
class Pet
{
private:
	PetStat stats[];

public:

	// ## Members ##

	PetStat hunger;
	PetStat thirst;
	PetStat comfort;
	PetStat energy;
	PetStat satisfaction;


	// ## Constructor and Destructor ##

	Pet()
	{
		hunger = PetStat("Hunger", hungerStatTags);
		thirst = PetStat("Thirst", thirstStatTags);
		comfort = PetStat("Comfort", comfortStatTags);
		energy = PetStat("Energy", energyStatTags);
		satisfaction = PetStat("Satisfaction", satisfactionStatTags);
	}

	~Pet();


	const static string hungerStatTags[] = new string[]{
			"Stuffed",
			"Full",
			"Peckish",
			"Hungry",
			"Starving"
	};
	const static string thirstStatTags[] = new string[]{
		"Sated",
		"Quenched",
		"Thirsty",
		"Parched",
		"Dehydrated"
	};
	const static string comfortStatTags[] = new string[]{
		"Floating",
		"Comfortable",
		"Unbothered",
		"Uncomfortable",
		"Restless"
	};
	const static string energyStatTags[] = new string[]{
		"Hyper",
		"Energetic",
		"Relaxed",
		"Tired",
		"Exausted"
	};
	const static string satisfactionStatTags[] = new string[]{
		"Overjoyed",
		"Happy",
		"Content",
		"Disheartened",
		"Anguished"
	};
};

