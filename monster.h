#pragma once
#include "creature.h"
#include <ctime>

class Monster : public Creature {

public:
	enum Type { SLIME, ORC, DRAGON, MAX_TYPE };
	struct MonsterData {
		string name;
		int hp;
		int damage;
	};
	static MonsterData monster_data[MAX_TYPE];

	Monster(Type type) :Creature(monster_data[type].name, monster_data[type].hp,
		monster_data[type].damage)
	{}
	static Monster getRandomMonster() {
		int tmp = rand() % 3;
		return Monster(static_cast<Type>(tmp));
	}

};
Monster::MonsterData Monster::monster_data[Monster::MAX_TYPE]{
		{"slime",1,1},
		{"orc",4,2},
		{"dragon",20,4}
};