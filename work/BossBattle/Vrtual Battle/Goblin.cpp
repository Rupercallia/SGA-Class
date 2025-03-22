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
	cout << "고블린이 플레이어에게 " << _atk << "만큼의 데미지를 입혔습니다." << endl;
	return _atk;
}