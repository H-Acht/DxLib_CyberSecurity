#pragma once

class Enemy
{
public:
	int ePosX = 0;
	int ePosY = 0;
	int eGraph = 0;
	int eWidth = 0;
	int eHeight = 0;

	bool Exist;				//���݂̗L��

	bool DamageFlag;		//�e������������
	int DamageGraph = 0;	//�e�������������̕\��
	int DamageTimer = 0;	//�e�������������̕\��ς���Ă��鎞��
	int DamageCount = 0;	//����e������������
	bool	hitBox;			//�����蔻��̗L��

	void Init();
	void Update();
	void Draw();
};
