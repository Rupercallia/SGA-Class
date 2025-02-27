#include "framework.h"
#include "Monster.h"
#include "Player.h"
#include "Scene/ArrowScene.h"

Monster::Monster()
{
    _monster = make_shared<Quad>(L"Resource/monster.png");
    _monsterRect = make_shared<RectCollider>(Vector(0, 0), _monster->GetImageSize());

    _monsterRect->GetTransform()->SetPos(Vector(0, 0));
    _monster->GetTransform()->SetParent(_monsterRect->GetTransform());
    // playerRect : 최상위 => RootComponent

    _monsterRect->GetTransform()->SetScale(Vector(0.3f, 0.3f));
}

Monster::~Monster()
{
}

void Monster::PreUpdate()
{
	_monsterRect->Update();
}

void Monster::Update()
{
	_monster->Update();
}

void Monster::Render()
{
	_monster->Render();

}

void Monster::PostRender()
{
    _monsterRect->Render();
}

void Monster::Move()
{

}

void Monster::OnDamage()
{
    // ArrowScene의 _temp와 충돌 체크
    if (_monsterRect->IsCollision(_temp->CircleCollider()))
    {
        // 충돌 시 _monster를 false로 설정
        _monster = nullptr;
    }
}
