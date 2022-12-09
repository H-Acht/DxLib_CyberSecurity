#include "DxLib.h"

#include "SceneMain.h"
#include "SceneTitle.h"
#include "game.h"

void SceneMain::init()
{
	player.Init();

	for (auto& Enemy : enemy)
	{
		Enemy.Init();
	}
	for (auto& Shot : shot)
	{
		Shot.Init();
	}
}

void SceneMain::end()
{
	player.End();
	
	for (auto& Enemy : enemy)
	{
		Enemy.End();
	}
	
	for (auto& Shot : shot)
	{
		Shot.End();
	}
}

SceneBase* SceneMain::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	
	player.Update(shot, SHOT);
	
	for (int i = 0; i < ENEMY; i++)
	{
		enemy[i].Update();
	}

	for (auto& Shot : shot)
	{
		Shot.Update(enemy);
	}
	
	/*if (padState & PAD_INPUT_3)
	{
		return (new SceneTitle);
	}*/

	return this;
}

void SceneMain::draw()
{
	for (auto& Shot : shot)
	{
		Shot.Draw();
	}
	player.Draw();
	for (auto& Enemy : enemy)
	{
		Enemy.Draw();
	}
	DrawString(0, 0, "main", GetColor(255, 255, 255));
}