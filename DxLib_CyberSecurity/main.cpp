#include "DxLib.h"

#include "game.h"
#include "Player.h"
#include "Enemy.h"

#define ENEMY 30

//�v���O������Win Main����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //window���[�h�ݒ�
    ChangeWindowMode(Game::kWindowMode);
    //�E�B���h�E���ݒ�
    SetMainWindowText(Game::kTitleText);
    //��ʃT�C�Y�̐ݒ�
    SetGraphMode(1280, 720, 32);

    if (DxLib_Init() == -1)        // �c�w���C�u��������������
    {
        return -1;        // �G���[���N�����璼���ɏI��
    }

    //�_�u���o�b�t�@���[�h
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

        //��ʂ̃N���A
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



        //����ʂƕ\��ʂ�؂�ւ���
        ScreenFlip();


        //esc�L�[�ŏI��
        if (CheckHitKey(KEY_INPUT_ESCAPE))   break;

        //fps��60�ɌŒ�
        while (GetNowHiPerformanceCount() - time < 16667)
        {
        }
    }

    DxLib_End();            // �c�w���C�u�����g�p�̏I������

    return 0;            // �\�t�g�̏I��
}