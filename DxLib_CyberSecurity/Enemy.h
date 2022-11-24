#pragma once

struct Enemy
{
	int ePosX = 0;
	int ePosY = 0;
	int eGraph = 0;
	int eWidth = 0;
	int eHeight = 0;

	int count = 0;
};

void Init(Enemy& enemy);
void Update(Enemy& enemy);
void Draw(Enemy& enemy);