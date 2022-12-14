#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneMain.h"

void SceneTitle::init()
{
	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		// Scene切り替え
		return(new SceneMain);
	}
	
	return this;
}

void SceneTitle::draw()
{
	DrawString(0, 0, "タイトル画面", GetColor(255, 255, 255));
}