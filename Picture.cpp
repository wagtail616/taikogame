#include "Dxlib.h"
#include "Picture.h"

void Picture::Load() {
	//タイトル
	title = LoadGraph("picture/Title.png");
	
	//プレイ画面
	Play_Background = LoadGraph("picture/Play_Background.png");//背景
	Lane = LoadGraph("picture/Lane.png");//ノーツを流すレーン
	/*
	Taiko = LoadGraph("");//画面に置く太鼓
	Notes = LoadGraph("");//ドンとカッ
	Judge = LoadGraph("");//判定枠
	Split = LoadGraph("");//魂ゲージ
	Combo = LoadGraph("");//コンボ数
	*/
}
void Picture::Out(int x,int y, int draw) {
	DrawGraph(x,y,draw,TRUE);
};