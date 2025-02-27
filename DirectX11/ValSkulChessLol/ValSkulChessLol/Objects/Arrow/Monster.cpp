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
    // playerRect : �ֻ��� => RootComponent

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
    // ArrowScene�� _temp�� �浹 üũ
    if (_monsterRect->IsCollision(_temp->CircleCollider()))
    {
        // �浹 �� _monster�� false�� ����
        _monster = nullptr;
    }
}
