#include "pch.h"
#include "Creature.h"
#include "Player.h"
#include "Goblin.h"

int Creature::Attack(Creature* other)
{
	other->TakeDamage(_atk);
	return _atk;
}

void Creature::TakeDamage(int amount)
{
	_hp -= amount;
	if (_hp <= 0)
		_hp = 0;
}

void Creature::debuff(int amount)
{
	_atk -= amount;
	if (_atk <= 0)
		_atk = 0;
}

bool Creature::IsAlive()
{
	return _hp > 0;
}
