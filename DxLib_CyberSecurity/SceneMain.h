#pragma once
#include "SceneBase.h"
#include"Player.h"
#include"Enemy.h"
#include"Shot.h"
#include "game.h"

class SceneMain : public SceneBase
{
public:
	SceneMain()
	{
	}
	virtual ~SceneMain() {}


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	Player player;
	Enemy enemy[ENEMY];
	Shot shot[SHOT];
};