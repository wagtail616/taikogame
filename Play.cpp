#include "Dxlib.h"
#include "Picture.h"
#include "Play.h"

void PLAY::Set(Picture picture) {

	picture.Out(0, 0, picture.Play_Background);//タイトル画面の描画
};