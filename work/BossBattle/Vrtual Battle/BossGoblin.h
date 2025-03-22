#pragma once

class Goblin;
class Player;
class BossGoblin : public Goblin
{
public:
	BossGoblin();
	BossGoblin(int hp, int atk);

	virtual int Attack(Creature* other);

private:
};
