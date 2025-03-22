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
	cout << "Player " << _name << "�� ��� ŷ���� " << _atk << "��ŭ�� �������� �������ϴ�." << endl;
	return _atk;
}
