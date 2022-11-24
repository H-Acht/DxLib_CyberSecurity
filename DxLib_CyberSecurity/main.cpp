#include "DxLib.h"

#include "game.h"
#include "Player.h"
#include "Enemy.h"

#define ENEMY 30

//プログラムはWin Mainから始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //windowモード設定
    ChangeWindowMode(Game::kWindowMode);
    //ウィンドウ名設定
    SetMainWindowText(Game::kTitleText);
    //画面サイズの設定
    SetGraphMode(1280, 720, 32);

    if (DxLib_Init() == -1)        // ＤＸライブラリ初期化処理
    {
        return -1;        // エラーが起きたら直ちに終了
    }

    //ダブルバッファモード
    SetDrawScreen(DX_SCREEN_BACK);

    Player player;
    Init(player);

    Enemy enemy[ENEMY];
    for (int i = 0; i < ENEMY; i++)
    {
        Init(enemy[i]);
    }

    while (ProcessMessage() == 0)
    {
        LONGLONG time = GetNowHiPerformanceCount();

        //画面のクリア
        ClearDrawScreen();

        Update(player);
        Draw(player);

        enemy->count++;
        if (enemy->count % 60 == 0)
        {
            for (int i = 0; i < ENEMY; i++)
            {
                Update(enemy[i]);
                Draw(enemy[i]);
            }
        }



        //裏画面と表画面を切り替える
        ScreenFlip();


        //escキーで終了
        if (CheckHitKey(KEY_INPUT_ESCAPE))   break;

        //fpsを60に固定
        while (GetNowHiPerformanceCount() - time < 16667)
        {
        }
    }

    DxLib_End();            // ＤＸライブラリ使用の終了処理

    return 0;            // ソフトの終了
}