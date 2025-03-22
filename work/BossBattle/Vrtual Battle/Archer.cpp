#include "pch.h"

Archer::Archer(string name, int hp, int atk)
	: Player(name, hp, atk)
{

}

int Archer::Attack(Creature* other)
{
	other->TakeDamage(_atk);
	cout << "-------------------------------------------------------------" << endl;
	cout << "Archer " << _name << "가 고블린 킹에게 " << _atk << "만큼의 데미지를 입혔습니다." << endl;
	int skill = rand() % 100;
	if (skill > 90)
	{
		cout << "-------------------------------------------------------------" << endl;
		cout << "스킬발동!!" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "확률적으로 적을 추가 공격 합니다." << endl;
		other->TakeDamage(_atk);
		cout << "-------------------------------------------------------------" << endl;
		cout << "Archer " << _name << "가 고블린에게 " << _atk << "만큼의 데미지를 입혔습니다." << endl;
		return _atk;
	}
}
