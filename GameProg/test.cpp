#include "DxLib.h"

int GetHitKeyStateAll_2(int KeyStateBuf[]) {
    char GetHitKeyStateAll_Key[256];
    GetHitKeyStateAll(GetHitKeyStateAll_Key);
    for (int i = 0; i < 256; i++) {
        if (GetHitKeyStateAll_Key[i] == 1) KeyStateBuf[i]++;
        else                            KeyStateBuf[i] = 0;
    }
    return 0;
}

void char_disp(int White, int y) {
    DrawString(150, y, "■", White);
    DrawString(170, 100, "NEW GAME", White);
    DrawString(170, 120, "CONTINUE1", White);
    DrawString(170, 140, "CONTINUE2", White);
    DrawString(170, 160, "CONTINUE3", White);
    DrawString(170, 180, "CONTINUE4", White);
    DrawString(170, 200, "CONTINUE5", White);
    DrawString(170, 220, "CONTINUE6", White);
    DrawString(170, 240, "LOG OUT", White);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    int Key[256];
    int White, y = 100;                                       //色とy座標の宣言

    ChangeWindowMode(TRUE);//ウィンドウモード
    if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//初期化と裏画面化

    White = GetColor(255, 255, 255);                    //色の取得


    while (ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll_2(Key) == 0 && Key[KEY_INPUT_ESCAPE] == 0) {
        //↑ﾒｯｾｰｼﾞ処理         ↑画面をｸﾘｱ         ↑入力状態を保存　　　　　　　↑ESCが押されていない

        char_disp(White, y);                              // 文字を描画

        if (Key[KEY_INPUT_DOWN] == 1 || (Key[KEY_INPUT_DOWN] % 5 == 0 && Key[KEY_INPUT_DOWN] > 30)) {
            // たった今押したか、30カウンター以上押しっぱなしかつ5回に一度
            y += 20;
            if (y == 260)                            // y座標が260なら(選択が一番下なら)
                y = 100;                        // 選択座標を一番上に
        }

        ScreenFlip();//裏画面反映
    }

    DxLib_End();
    return 0;
}