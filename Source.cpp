#include <iostream>
#include <string>
#include <cstdlib> // для rand() и srand()
#include <ctime> // для time()
#include "creature.h"
#include "player.h"
#include "monster.h"

using namespace std;
void fightWithMonster(Player&, Monster&);//бой между монстром и игроком
void attackPlayer(Player&, Monster);//монстр атакует игрока
void attackMonster(Player&, Monster&);//игрок атакует монстра
int main()
{
	//setlocale(LC_ALL, "rus");
	srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	rand(); // сбрасываем первый результат

	Player player1("Uri",10,1); //создаём игрока
	//игровой цикл
	// bool run = true;
	while (true) {
	//while(run)
		Monster monster = Monster::getRandomMonster();
		//сражение игрока с монстром
		fightWithMonster(player1, monster);
		if (player1.isDead()) {
			cout << "You lose the game \n";
			break;
			//run = false;
		}
		if (!player1.isDead() && player1.getLevel() == 20) {
			cout << "You win!\n";
			break;
		}
		

	}

	return 0;
}
void fightWithMonster(Player &player, Monster &monster) {
	cout << "You have encountered a " << monster.getName() << ".\n";
	while (!player.isDead() && !monster.isDead()) {
		cout << "(R)un or (F)ight: ";
		char choice;
		cin >> choice;
		//игрок убегает
		if (choice == 'r' || choice == 'R') {
			//сбежал
			if (rand() % 10 < 5) {
				cout << "You successfully fled\n";
				return;
			}
			//не удалось сбежать
			else {
				cout << "You failed to fled\n";
				attackPlayer(player, monster);
				continue;
			}
		}
		//игрок атакует монстра
		if (choice == 'f' || choice == 'F') {
			attackMonster(player, monster);
			attackPlayer(player, monster);
		}
	}
}
void attackPlayer(Player &player, Monster monster) {
	if (monster.isDead()) return;
	player.reduceHealth(monster.getDamage());
	cout << "The " << monster.getName() << " hit you for " << monster.getDamage() <<
		" damage\n";

}
void attackMonster(Player &player, Monster &monster) {
	if (player.isDead()) return;
	monster.reduceHealth(player.getDamage());
	cout << player.getName() << " hit " << monster.getName() << " for " <<
		player.getDamage() << " damage\n";
	if (monster.isDead()) {
		cout << "You killed the " << monster.getName() << "\n";
		player.levelUp();
		cout << "Your level now is " << player.getLevel() << "\n";
	}

}

