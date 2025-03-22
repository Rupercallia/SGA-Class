#include "pch.h"

Goblin::Goblin()
{
	_hp = rand() % 200 + 200;
	_atk = rand() % 10 + 10;
}

Goblin::Goblin(int hp, int atk)
	:Creature(hp, atk)
{
}

int Goblin::Attack(Creature* other)
{
	other->TakeDamage(_atk);
	cout << "-------------------------------------------------------------" << endl;
	cout << "����� �÷��̾�� " << _atk << "��ŭ�� �������� �������ϴ�." << endl;
	return _atk;
}