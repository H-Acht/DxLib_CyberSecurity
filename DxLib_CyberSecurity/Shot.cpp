#include "Shot.h"
#include "game.h"
#include "Enemy.h"

void Shot::Init()
{
	sGraph = LoadGraph("Data/tama.png");
	// �e����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ��Ɂw���݂��Ă��Ȃ��x���Ӗ�����false����
	Exist = false;

	GetGraphSize(sGraph, &sWidth, &sHeight);
}

void Shot::End()
{
	DeleteGraph(sGraph);
}

void Shot::Update(Enemy enemy[])
{
	if (Exist == true)
	{
		for (int i =0; i < ENEMY; i++)
		{
			if (enemy[i].hitBox == true)
			{
				//�����蔻��
				if (((sPosX > enemy[i].ePosX && sPosX < enemy[i].ePosX + enemy[i].eWidth) ||
					(enemy[i].ePosX > sPosX && enemy[i].ePosX < sPosX + sWidth)) &&
					((sPosY > enemy[i].ePosY && sPosY < enemy[i].ePosY + enemy[i].eHeight) ||
						(enemy[i].ePosY > sPosY && enemy[i].ePosY < sPosY + sHeight)))
				{
					Exist = 0;

					enemy[i].DamageFlag = true;
					enemy[i].DamageTimer = 0;
					enemy[i].DamageCount += 1;
				}
			}
		}
		sPosY -= 18;

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