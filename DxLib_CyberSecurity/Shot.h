#pragma once
class Enemy;

class Shot
{
public:
	bool Exist = false;

	void Init();
	void End();
	void Update(Enemy enemy[]);
	void Draw();

	int	sPosX =0;
	int	sPosY =0;
	int	sGraph =0;
	int	sWidth =0;
	int	sHeight =0;
};
