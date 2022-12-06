#include "Enemy.h"
#include "game.h"

void Enemy::Init()
{
	eGraph = LoadGraph("Data/V1.png");
	ePosX = GetRand(1200);
	ePosY = -30;

	DamageGraph = LoadGraph("Data/VD1.png");
	DamageFlag = false;
	DamageCount = 0;
	Exist = true;
	hitBox = true;

	GetGraphSize(eGraph, &eWidth, &eHeight);
}

void Enemy::Update()
{
	ePosY += 3;
	
	//’e‚ª5‰ñ“–‚½‚Á‚½
	if (DamageCount >= 5)
	{
		ePosY -= 3;
		//‘¶İ‚ğÁ‚·
		Exist = false;
		//“–‚½‚è”»’è‚ğÁ‚·
		hitBox = false;
	}
}

void Enemy::Draw()
{
	if (DamageFlag == true)
	{
		if (DamageCount <= 5)
		{
			DrawGraph(ePosX, ePosY, DamageGraph, TRUE);

			DamageTimer++;

			if (DamageTimer == 10)
			{
				DamageFlag = false;
			}
		}
	}
	else
	{
		if (Exist == true)
		{
			DrawGraph(ePosX, ePosY, eGraph, true);
		}
	}
}