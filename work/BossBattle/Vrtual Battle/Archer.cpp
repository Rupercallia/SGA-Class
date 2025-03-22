#include "pch.h"

Archer::Archer(string name, int hp, int atk)
	: Player(name, hp, atk)
{

}

int Archer::Attack(Creature* other)
{
	other->TakeDamage(_atk);
	cout << "-------------------------------------------------------------" << endl;
	cout << "Archer " << _name << "�� ��� ŷ���� " << _atk << "��ŭ�� �������� �������ϴ�." << endl;
	int skill = rand() % 100;
	if (skill > 90)
	{
		cout << "-------------------------------------------------------------" << endl;
		cout << "��ų�ߵ�!!" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "Ȯ�������� ���� �߰� ���� �մϴ�." << endl;
		other->TakeDamage(_atk);
		cout << "-------------------------------------------------------------" << endl;
		cout << "Archer " << _name << "�� ������� " << _atk << "��ŭ�� �������� �������ϴ�." << endl;
		return _atk;
	}
}
