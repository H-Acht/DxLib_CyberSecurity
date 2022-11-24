#include "Player.h"
#include "DxLib.h"

void Init(Player& player)
{
	player.pGraph = LoadGraph("Data/Jiki.png");

	player.pPosX = 640;
	player.pPosY = 600;

	GetGraphSize(player.pGraph, &player.pWidth, &player.pHeight);
}

void Update(Player& player)
{
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		player.pPosY -= 3;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		player.pPosY += 3;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		player.pPosX -= 3;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		player.pPosX += 3;
	}
}

void Draw(Player& player)
{
	DrawGraph(player.pPosX, player.pPosY, player.pGraph, true);
}