#include "DxLib.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
    ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɐݒ�
    DxLib_Init();   // DX���C�u��������������
    WaitKey();      // �L�[���͑҂�
    DxLib_End();    // DX���C�u�����I������
    return 0;
}