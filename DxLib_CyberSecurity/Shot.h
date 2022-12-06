#pragma once
class Enemy;

class Shot
{
public:
	int	sPosX;
	int	sPosY;
	int	sGraph;
	int	sWidth;
	int	sHeight;

	bool Exist;

	void Init();
	void Update(Enemy& enemy);
	void Draw();
};
