#pragma once

class Enemy
{
public:
	int ePosX = 0;
	int ePosY = 0;
	int eGraph = 0;
	int eWidth = 0;
	int eHeight = 0;

	bool Exist;				//‘¶İ‚Ì—L–³

	bool DamageFlag;		//’e‚ª“–‚½‚Á‚½‚©
	int DamageGraph = 0;	//’e‚ª“–‚½‚Á‚½‚Ì•\î
	int DamageTimer = 0;	//’e‚ª“–‚½‚Á‚½‚Ì•\î‚ª•Ï‚í‚Á‚Ä‚¢‚éŠÔ
	int DamageCount = 0;	//‰½‰ñ’e‚ª“–‚½‚Á‚½‚©
	bool	hitBox;			//“–‚½‚è”»’è‚Ì—L–³

	void Init();
	void Update();
	void Draw();
};
