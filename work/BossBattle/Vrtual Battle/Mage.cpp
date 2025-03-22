#include "pch.h"

Mage::Mage(string name, int hp, int atk)
	: Player(name, hp, atk)
{
	
}

int Mage::Attack(Creature* other)
{
	other->TakeDamage(_atk);
	cout << "-------------------------------------------------------------" << endl;
	cout << "Mage " << _name << "가 고블린 킹에게 " << _atk << "만큼의 데미지를 입혔습니다." << endl;
	int skill = rand() % 100;
	if (skill > 80)
	{
		cout << "-------------------------------------------------------------" << endl;
		cout << "스킬발동!!" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "확률적으로 적의 공격력을 내립니다." << endl;
		other->debuff(2);
		cout << "-------------------------------------------------------------" << endl;
		cout << "적의 공격력이 감소했습니다." << endl;
		return _atk;
	}
}
