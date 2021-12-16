#include <iostream>
using namespace std;
class Creature{
protected:
	string m_name;
	int m_hp;
	int m_damage;
public:
	Creature(string name, int hp, int damage):
		m_name{ name }, m_hp{ hp }, m_damage{ damage }
	{}
	void setName(string name) { m_name = name; }
	void setHp(int hp) { m_hp = hp; }
	void setDamage(int damage) { m_damage = damage; }
	string getName() { return m_name; }
	int getHp() { return m_hp; }
	int getDamage() { return m_damage; }
	void reduceHealth(int dmg) { m_hp -= dmg; }
	bool isDead() {
		if (m_hp <= 0)  return true;
		else return false;
		// return m_hp <=0;
	}
};
class Player : public Creature {
private:
	const int full_hp = 10;
	int m_level;
public:
	Player(string name, int hp, int damage, int level = 1) :
		Creature(name, hp, damage), m_level{level}
	{}
	void setLevel(int level) { m_level = level; }
	int getLevel() { return m_level; }
	void levelUp() {
		m_hp = full_hp;
		m_damage++;
		m_level++;
	}
	bool hasWon() {
		return m_level == 11;
	}
};
class Monster : public Creature {
	enum Type {SLIME, ORC, DRAGON, MAX_TYPE};
};