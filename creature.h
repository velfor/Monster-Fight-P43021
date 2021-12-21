#pragma once
#include <string>
using namespace std;
class Creature {
protected:
	string m_name;
	int m_hp;
	int m_damage;
public:
	Creature(string name, int hp, int damage) :
		m_name{ name }, m_hp{ hp }, m_damage{ damage }
	{}
	void setName(string name) { m_name = name; }
	void setHp(int hp) { m_hp = hp; }
	void setDamage(int damage) { m_damage = damage; }
	string getName() { return m_name; }
	int getHp() { return m_hp; }
	int getDamage() { return m_damage; }
	void reduceHealth(int dmg) { m_hp -= dmg; }
	bool isDead();
};