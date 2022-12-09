#include "Player.h"
#include "Shot.h"
#include "game.h"

void Player::Init()
{
	pGraph = LoadGraph("Data/Jiki.png");

	GetGraphSize(pGraph, &pWidth, &pHeight);

	pPosX = Game::kScreenWidth/2 -50;
	pPosY = Game::kScreenHeight-150;
}

void Player::End()
{
	DeleteGraph(pGraph);
}

void Player::Update(Shot shot[], int shotArraySize)
{
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		pPosY -= 5;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		pPosY += 5;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		pPosX -= 5;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		pPosX += 5;
	}

	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		// �O�t���[���ŃV���b�g�{�^���������������ۑ�����Ă���ϐ���false��������e�𔭎�
		if (prevShotFlag == false)
		{
			// ��ʏ�ɂłĂ��Ȃ��e�����邩�A�e�̐������J��Ԃ��Ē��ׂ�
			for (int i = 0; i < shotArraySize; i++)
			{
				// �ei����ʏ�ɂłĂ��Ȃ��ꍇ�͂��̒e����ʂɏo��
				if (shot[i].Exist == false)
				{
					// �ei�̈ʒu���Z�b�g�A�ʒu�̓v���C���[�̒��S�ɂ���
					shot[i].sPosX = (pWidth - shot[i].sWidth) / 2 + pPosX;
					shot[i].sPosY = (pHeight - shot[i].sHeight) / 2 + pPosY;

					// �ei�͌����_�������đ��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ���true��������
					shot[i].Exist = true;

					// ��e���o�����̂Œe���o�����[�v���甲���܂�
					break;
				}
			}
		}
		// �O�t���[���ŃV���b�g�{�^����������Ă�������ۑ�����ϐ���true(������Ă���)����
		prevShotFlag = true;
	}
	else
	{
		prevShotFlag = false;
	}
}

void Player::Draw()
{
	DrawGraph(pPosX, pPosY, pGraph, true);
}