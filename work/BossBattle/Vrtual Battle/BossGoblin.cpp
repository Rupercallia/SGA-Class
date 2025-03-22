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
	cout << "고블린 킹이 플레이어에게 " << _atk << "만큼의 데미지를 입혔습니다." << endl;
	return _atk;
}
