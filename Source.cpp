#include <iostream>
#include <string>
#include <cstdlib> // ��� rand() � srand()
#include <ctime> // ��� time()
#include "creature.h"
#include "player.h"
#include "monster.h"

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0))); // ������������� �������� ��������� ����� � �������� ���������� �����
	rand(); // ���������� ������ ���������

	for (int i = 0; i < 10; ++i)
	{
		Monster m = Monster::getRandomMonster();
		std::cout << "A " << m.getName() << " was created.\n";
	}

	return 0;
}


