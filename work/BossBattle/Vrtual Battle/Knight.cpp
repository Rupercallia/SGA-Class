#include "pch.h"

Knight::Knight(string name, int hp, int atk)
	: Player(name, hp, atk)
{

}

int Knight::Attack(Creature* other)
{
	if (_hp <= 100)
	{
		_atk += 1;
		cout << "-------------------------------------------------------------" << endl;
		cout << "스킬발동!!" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "체력이 낮은 상태에서 공격을 받아 공격력이 1 상승했습니다." << endl;
	}
	other->TakeDamage(_atk);
	cout << "-------------------------------------------------------------" << endl;
	cout << "Knight " << _name << "가 고블린 킹에게 " << _atk << "만큼의 데미지를 입혔습니다." << endl;
	return _atk;
}
