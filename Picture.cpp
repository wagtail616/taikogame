#include "Dxlib.h"
#include "Picture.h"

void Picture::Load() {
	//タイトル
	title = LoadGraph("picture/Title.png");
	/*
	//プレイ画面
	Play_background  = LoadGraph("");//背景
	taiko = LoadGraph("");//画面に置く太鼓
	lane  = LoadGraph("");//ノーツを流すレーン
	notes = LoadGraph("");//ドンとカッ
	judge = LoadGraph("");//判定枠
	split = LoadGraph("");//魂ゲージ
	combo = LoadGraph("");//コンボ数
	*/
}
void Out(int x,int y, int draw) {
	DrawGraph(x,y,draw,TRUE);
};