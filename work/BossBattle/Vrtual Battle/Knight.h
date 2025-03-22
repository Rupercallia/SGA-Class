#pragma once

class Goblin;
class Player;
class Knight : public Player
{
public:
	Knight() {}
	Knight(string name, int hp, int atk);

	virtual int Attack(Creature* other);
};

