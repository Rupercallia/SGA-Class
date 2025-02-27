#pragma once
#include "Scene/ArrowScene.h"
class Monster
{
public:
	Monster();
	~Monster();

	void PreUpdate();
	void Update();

	void Render();
	void PostRender();

	void Move();
	void OnDamage();

	bool isActive = false;
private:
	shared_ptr<Quad> _monster;
	shared_ptr<RectCollider> _monsterRect;
	shared_ptr<class Player> _player;
	shared_ptr<RectCollider> _playerRect;
	shared_ptr<class ArrowScene> _temp;
};
