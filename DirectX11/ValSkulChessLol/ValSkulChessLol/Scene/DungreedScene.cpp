#include "framework.h"
#include "DungreedScene.h"
#include "ArrowScene.h"

#include "Objects/Arrow/Player.h"
#include "Objects/Arrow/Arrow.h"

BamSurviver::BamSurviver()
{
	_backGround = make_shared<Quad>(L"Resource/Map.png");
	_player = make_shared<Player>();
	_backGround->GetTransform()->SetPos(CENTER);
	_backGround->GetTransform()->SetScale(Vector(1.5f, 1.5f));
	_backGround->AddColor(XMFLOAT4(0.2f, 0.2f, 0.2f, 0.0f));
	_backGround->Update();
	_bow->GetTransform()->SetParent(_player);
}

BamSurviver::~BamSurviver()
{
}

void BamSurviver::PreUpdate()
{
	_player->PreUpdate();
}

void BamSurviver::Update()
{
	_player->Update();
}

void BamSurviver::Render()
{
	_backGround->Render();

	_player->Render();
}

void BamSurviver::PostRender()
{
	_player->PostRender();
}

