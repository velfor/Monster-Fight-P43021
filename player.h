#pragma once
#include <string>
#include "creature.h"
using namespace std;

class Player : public Creature {
private:
	const int full_hp = 10;
	int m_level;
public:
	Player(string name, int hp, int damage, int level = 1) :
		Creature(name, hp, damage), m_level{ level }
	{}
	void setLevel(int level) { m_level = level; }
	int getLevel() { return m_level; }
	void levelUp();
	bool hasWon();
};