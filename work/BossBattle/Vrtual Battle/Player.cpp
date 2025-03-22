#include "pch.h"

Player::Player(string name, int hp, int atk)
	: _name(name)
	, Creature(hp, atk)
{
}

int Player::Attack(Creature* other)
{
	other->TakeDamage(_atk);
	cout << "-------------------------------------------------------------" << endl;
	cout << "Player " << _name << "가 고블린 킹에게 " << _atk << "만큼의 데미지를 입혔습니다." << endl;
	return _atk;
}
