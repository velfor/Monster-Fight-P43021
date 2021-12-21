#include "creature.h"
bool Creature::isDead() {
	if (m_hp <= 0)  return true;
	else return false;
	// return m_hp <=0;
}