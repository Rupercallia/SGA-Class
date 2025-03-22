#pragma once

class Goblin : public Creature
{
public:
	Goblin();
	Goblin(int hp, int atk);

	virtual int Attack(Creature* other);

private:
};

