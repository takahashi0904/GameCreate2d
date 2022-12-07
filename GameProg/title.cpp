#include "title.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�

//������
void title_Initialize() {
    mImageHandle = LoadGraph("images/Scene_Menu.png");    //�摜�̃��[�h
}

//�I������
void title_Finalize() {
    DeleteGraph(mImageHandle);    //�摜�̉��
}

//�X�V
void title_Update() {
    if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_C) != 0) {//C�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Clear);//�V�[����ݒ��ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_O) != 0) {//C�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Over);//�V�[����ݒ��ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_M) != 0) {//C�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Menu);//�V�[����ݒ��ʂɕύX
    }
}

//�`��
void title_Draw() {
    DrawGraph(0, 0, mImageHandle, FALSE);
    DrawString(0, 0, "�^�C�g����ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "G�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
    DrawString(0, 40, "C�L�[�������Ɓ@�N���A��ʂɐi�݂܂��B", GetColor(255, 255, 255));
    DrawString(0, 60, "O�L�[�������Ɓ@�I�[�o�[��ʂɐi�݂܂��B", GetColor(255, 255, 255));
    DrawString(0, 80, "M�L�[�������Ɓ@���j���[��ʂɐi�݂܂��B", GetColor(255, 255, 255));

   

}