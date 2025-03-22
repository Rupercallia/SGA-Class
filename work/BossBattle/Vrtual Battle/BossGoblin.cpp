#include "pch.h"
#include "Player.h"
#include "BossGoblin.h"

BossGoblin::BossGoblin()
{
	_hp = rand() % 200 + 2000;
	_atk = rand() % 25 + 20;
}

BossGoblin::BossGoblin(int hp, int atk)
{
}

int BossGoblin::Attack(Creature* other)
{
	other->TakeDamage(_atk);
	cout << "-------------------------------------------------------------" << endl;
	cout << "��� ŷ�� �÷��̾�� " << _atk << "��ŭ�� �������� �������ϴ�." << endl;
	return _atk;
}
