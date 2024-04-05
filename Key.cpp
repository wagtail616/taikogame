#include "Key.h"
#include"DxLib.h"

int Key::GetHitKey()
{
    char allkey[256];//�L�[��������Ă��邩
    GetHitKeyStateAll(allkey);
    for (int i = 0; i < 256; i++) {
        if (allkey[i] ==1) {
            Key[i]++;
        }
        else if (allkey[i] == 0) {
            Key[i] = 0;
        }
    }
    return 0;
}



//�L�[���͂���ƌ���
void Key::ScreenBright(Picture picture) {
    
    if (GetKey(KEY_INPUT_J)) {
        picture.Out(0, 260, picture.BrightD);
    };
    if (GetKey(KEY_INPUT_D)) {
        picture.Out(0, 260, picture.BrightD);
    };
    if (GetKey(KEY_INPUT_K)) {
        picture.Out(0, 260, picture.BrightK);
    };
    if (GetKey(KEY_INPUT_S)) {
        picture.Out(0, 260, picture.BrightK);
    };
}

bool Key::GetKey(char key) {
    return Key[key] != 0;
}