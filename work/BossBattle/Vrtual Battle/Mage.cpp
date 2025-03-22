#include "pch.h"

Mage::Mage(string name, int hp, int atk)
	: Player(name, hp, atk)
{
	
}

int Mage::Attack(Creature* other)
{
	other->TakeDamage(_atk);
	cout << "-------------------------------------------------------------" << endl;
	cout << "Mage " << _name << "�� ��� ŷ���� " << _atk << "��ŭ�� �������� �������ϴ�." << endl;
	int skill = rand() % 100;
	if (skill > 80)
	{
		cout << "-------------------------------------------------------------" << endl;
		cout << "��ų�ߵ�!!" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "Ȯ�������� ���� ���ݷ��� �����ϴ�." << endl;
		other->debuff(2);
		cout << "-------------------------------------------------------------" << endl;
		cout << "���� ���ݷ��� �����߽��ϴ�." << endl;
		return _atk;
	}
}
