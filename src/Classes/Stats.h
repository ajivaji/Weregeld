
#ifndef WEREGELD_STATS_H
#define WEREGELD_STATS_H
namespace WG {
struct Stats {
	int health;
	int strength;
	int dexterity;
	int intelligence;
	int wisdom;
	int charisma;
	int constitution;
	int luck;
	int perception;
	int endurance;
	int agility;
	int speed;
	int size;
	int weight;
};

struct Appearance {
	std::string hairColor;
	std::string eyeColor;
	std::string skinColor;
	std::string hairStyle;
	std::string facialHairStyle;
};
}

#endif //WEREGELD_STATS_H
