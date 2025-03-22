#pragma once

class Archer : public Player
{
public:
	Archer() {}
	Archer(string name, int hp, int atk);

	int Attack(Creature* other);
};

