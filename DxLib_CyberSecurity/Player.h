#pragma once

struct Player
{
	int pPosX = 0;
	int pPosY = 0;
	int pGraph = 0;
	int pWidth = 0;
	int pHeight = 0;

	bool prevShotFlag = false;
};

void Init(Player& player);
void Update(Player& player);
void Draw(Player& player);