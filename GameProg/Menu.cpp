#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle;    //画像ハンドル格納用変数

//初期化
void Menu_Initialize() {
    mImageHandle = LoadGraph("images/Scene_Menu.png");    //画像のロード
}

//終了処理
void Menu_Finalize() {
    DeleteGraph(mImageHandle);    //画像の解放
}

//更新
void Menu_Update() {
   
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_title);//シーンをメニューに変更
    }
}

//描画
void Menu_Draw() {
    DrawGraph(0, 0, mImageHandle, FALSE);
    DrawString(0, 0, "メニュー画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Escキーを押すとタイトル画面に戻ります。", GetColor(255, 255, 255));

}