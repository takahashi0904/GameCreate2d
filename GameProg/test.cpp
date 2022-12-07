#include "DxLib.h"
#include "SceneMgr.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

    SceneMgr_Initialize();

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���

        SceneMgr_Update();  //�X�V
        SceneMgr_Draw();    //�`��

    }

    SceneMgr_Finalize();

    DxLib_End(); // DX���C�u�����I������
    return 0;
}