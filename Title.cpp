#include "Dxlib.h"
#include "Title.h"
#include "Picture.h"

void TITLE::Set(Picture picture){

	picture.Out(0,0,picture.title);//タイトル画面の描画
};