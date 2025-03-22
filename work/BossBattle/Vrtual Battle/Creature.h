#pragma once
class Creature
{
public:
	Creature() : _hp(0), _atk(0) {}
	Creature(int hp, int atk) : _hp(hp), _atk(atk) {}

	virtual int Attack(Creature* other)abstract;
	void TakeDamage(int amount);
	void debuff(int amount);
	bool IsAlive();

protected:
	int _hp;
	int _atk;
};

