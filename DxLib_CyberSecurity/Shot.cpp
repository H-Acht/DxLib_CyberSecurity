#include "Shot.h"
#include "game.h"
#include "Enemy.h"

void Shot::Init()
{
	sGraph = LoadGraph("Data/tama.png");
	// ’e‚ª‰æ–Êã‚É‘¶Ý‚µ‚Ä‚¢‚é‚©•ÛŽ‚·‚é•Ï”‚Éw‘¶Ý‚µ‚Ä‚¢‚È‚¢x‚ðˆÓ–¡‚·‚éfalse‚ð‘ã“ü
	Exist = false;

	GetGraphSize(sGraph, &sWidth, &sHeight);
}

void Shot::Update(Enemy& enemy)
{
	if (Exist == true)
	{
		if (enemy.hitBox == true)
		{
			//“–‚½‚è”»’è
			if (((sPosX > enemy.ePosX && sPosX < enemy.ePosX + enemy.eWidth) ||
				(enemy.ePosX > sPosX && enemy.ePosX < sPosX + sWidth)) &&
				((sPosY > enemy.ePosY && sPosY < enemy.ePosY + enemy.eHeight) ||
					(enemy.ePosY > sPosY && enemy.ePosY < sPosY + sHeight)))
			{
				Exist = 0;

				enemy.DamageFlag = true;
				enemy.DamageTimer = 0;
				enemy.DamageCount += 1;
			}
		}
		sPosY -= 16;

		if (sPosY < 0 - sHeight)
		{
			Exist = false;
		}
	}
}

void Shot::Draw()
{
	if (Exist == true)
	{
		DrawGraph(sPosX, sPosY, sGraph, TRUE);
	}
}