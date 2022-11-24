#include "Enemy.h"
#include "DxLib.h"

void Init(Enemy& enemy)
{
	enemy.eGraph = LoadGraph("Data/V1.png");

	enemy.ePosX = GetRand(1200);
	enemy.ePosY = 0;

	GetGraphSize(enemy.eGraph, &enemy.eWidth, &enemy.eHeight);
}

void Update(Enemy& enemy)
{
	enemy.ePosY += 1;
}

void Draw(Enemy& enemy)
{
	DrawGraph(enemy.ePosX, enemy.ePosY, enemy.eGraph, true);
}