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
		cout << "��ų�ߵ�!!" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "ü���� ���� ���¿��� ������ �޾� ���ݷ��� 1 ����߽��ϴ�." << endl;
	}
	other->TakeDamage(_atk);
	cout << "-------------------------------------------------------------" << endl;
	cout << "Knight " << _name << "�� ��� ŷ���� " << _atk << "��ŭ�� �������� �������ϴ�." << endl;
	return _atk;
}
