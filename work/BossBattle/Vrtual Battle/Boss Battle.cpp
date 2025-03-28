#include "pch.h"

void Battle(vector<Player*>& players, Creature* g)
{
	cout << "-------------------------------------------------------------" << endl;
	cout << "고블린 킹과 전투를 시작합니다." << endl;

    while (g->IsAlive()) 
    {
        vector<pair<int, Player*>> damageList;
        
        for (auto player : players) 
        {
            if (player->IsAlive()) 
            {
                int damage = player->Attack(g);
                damageList.emplace_back(damage, player);
            }
        }

        if (!g->IsAlive()) 
        {
            cout << "-------------------------------------------------------------" << endl;
            cout << "고블린 킹이 쓰러졌습니다!" << endl;
            break;
        }

        cout << "-------------------------------------------------------------" << endl;
        cout << "고블린 킹이 가장 위협적인 4명을 공격합니다!" << endl;

        sort(damageList.begin(), damageList.end(), greater());

        int count = 0;
        for (auto& [damage, player] : damageList)
        {
            if (count >= 4) break;
            if (player->IsAlive())
            {
                g->Attack(player);
                count++;
            }
        }

        auto allDead = all_of(players.begin(), players.end(), [](auto player)
            {
                return !player->IsAlive();
            });

        if (allDead) 
        {
            cout << "-------------------------------------------------------------" << endl;
            cout << "파티가 전멸했습니다!" << endl;
            break;
        }

    }
}

int main()
{
	srand(time(nullptr));

	Creature* g = new BossGoblin;
	vector<Player*> players;

	for (int i = 0; i < 10; i++)
	{
		int r = rand() % 3;
		if (r == 0)
			players.push_back(new Mage("", rand() % 150 + 100, rand() % 15 + 10));
		else if (r == 1)
			players.push_back(new Knight("", rand() % 300 + 200, rand() % 8 + 5));
		else
			players.push_back(new Archer("", rand() % 225 + 150, rand() % 12 + 7));
	}

	Battle(players, g);

    for (auto Player : players)
    {
        delete Player;
    }

	delete g;

	return 0;
}