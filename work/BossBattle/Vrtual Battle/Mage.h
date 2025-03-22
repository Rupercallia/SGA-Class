#pragma once

class Goblin;
class Player;
class Mage : public Player
{
public:
	Mage(string name, int hp, int atk);

	virtual int Attack(Creature* other);
};

