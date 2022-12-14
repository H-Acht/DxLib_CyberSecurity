#pragma once

class Enemy
{
public:
	int ePosX = 0;
	int ePosY = 0;
	int eGraph = 0;
	int eWidth = 0;
	int eHeight = 0;

	bool Exist;				//存在の有無

	bool DamageFlag;		//弾が当たったか
	int DamageGraph = 0;	//弾が当たった時の表情
	int DamageTimer = 0;	//弾が当たった時の表情が変わっている時間
	int DamageCount = 0;	//何回弾が当たったか
	bool hitBox;			//当たり判定の有無

	void Init();
	void End();
	void Update();
	void Draw();
};
