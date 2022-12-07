#include "Clear.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�

//������
void Clear_Initialize() {
    mImageHandle = LoadGraph("images/Scene_Game.png");    //�摜�̃��[�h
}

//�I������
void Clear_Finalize() {
    DeleteGraph(mImageHandle);    //�摜�̉��
}

//�X�V
void Clear_Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_title);//�V�[�������j���[�ɕύX
    }
}

//�`��
void Clear_Draw() {
    DrawGraph(0, 0, mImageHandle, FALSE);
    DrawString(0, 0, "�N���A��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "Esc�L�[�������ƃ^�C�g����ʂɖ߂�܂��B", GetColor(255, 255, 255));
}