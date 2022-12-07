#include "title.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle;    //画像ハンドル格納用変数

//初期化
void title_Initialize() {
    mImageHandle = LoadGraph("images/Scene_Menu.png");    //画像のロード
}

//終了処理
void title_Finalize() {
    DeleteGraph(mImageHandle);    //画像の解放
}

//更新
void title_Update() {
    if (CheckHitKey(KEY_INPUT_G) != 0) {//Gキーが押されていたら
        SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
    }
    if (CheckHitKey(KEY_INPUT_C) != 0) {//Cキーが押されていたら
        SceneMgr_ChangeScene(eScene_Clear);//シーンを設定画面に変更
    }
    if (CheckHitKey(KEY_INPUT_O) != 0) {//Cキーが押されていたら
        SceneMgr_ChangeScene(eScene_Over);//シーンを設定画面に変更
    }
    if (CheckHitKey(KEY_INPUT_M) != 0) {//Cキーが押されていたら
        SceneMgr_ChangeScene(eScene_Menu);//シーンを設定画面に変更
    }
}

//描画
void title_Draw() {
    DrawGraph(0, 0, mImageHandle, FALSE);
    DrawString(0, 0, "タイトル画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Gキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
    DrawString(0, 40, "Cキーを押すと　クリア画面に進みます。", GetColor(255, 255, 255));
    DrawString(0, 60, "Oキーを押すと　オーバー画面に進みます。", GetColor(255, 255, 255));
    DrawString(0, 80, "Mキーを押すと　メニュー画面に進みます。", GetColor(255, 255, 255));

   

}