#pragma once

class Goblin;
class Player : public Creature
{
public:
	Player(){}
	Player(string name, int hp, int atk);

	virtual int Attack(Creature* other);


protected:
	string _name;
};
