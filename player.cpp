#include "player.h"

void Player::levelUp() {
	m_hp = full_hp;
	m_damage++;
	m_level++;
}
bool Player::hasWon() {
	return m_level == 11;
}