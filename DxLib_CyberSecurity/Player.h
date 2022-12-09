#pragma once

class Shot;
class Player
{
public:
	int pPosX = 0;
	int pPosY = 0;
	int pGraph = 0;
	int pWidth = 0;
	int pHeight = 0;

	//前フレームでショットボタンを押したか
	bool prevShotFlag = false;
	
	void Init();
	void End();
	void Update(Shot shot[], int shotArraySize);
	void Draw();
};
