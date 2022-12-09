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
		// 前フレームでショットボタンを押したかが保存されている変数がfalseだったら弾を発射
		if (prevShotFlag == false)
		{
			// 画面上にでていない弾があるか、弾の数だけ繰り返して調べる
			for (int i = 0; i < shotArraySize; i++)
			{
				// 弾iが画面上にでていない場合はその弾を画面に出す
				if (shot[i].Exist == false)
				{
					// 弾iの位置をセット、位置はプレイヤーの中心にする
					shot[i].sPosX = (pWidth - shot[i].sWidth) / 2 + pPosX;
					shot[i].sPosY = (pHeight - shot[i].sHeight) / 2 + pPosY;

					// 弾iは現時点を持って存在するので、存在状態を保持する変数にtrueを代入する
					shot[i].Exist = true;

					// 一つ弾を出したので弾を出すループから抜けます
					break;
				}
			}
		}
		// 前フレームでショットボタンを押されていたかを保存する変数にtrue(おされていた)を代入
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