#include "DxLib.h"

#include "game.h"

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

    while (ProcessMessage() == 0)
    {
        LONGLONG time = GetNowHiPerformanceCount();

        //��ʂ̃N���A
        ClearDrawScreen();

        DrawString(600, 360, "git�e�X�g �͂���", GetColor(255, 255, 255));
        DrawString(600, 400, "�t�@�C�� �͂���", GetColor(255, 255, 255));


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