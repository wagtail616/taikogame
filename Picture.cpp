#include "Dxlib.h"
#include "Picture.h"

void Picture::Load() {
	//タイトル
	title = LoadGraph("picture/Title.png");
	
	//プレイ画面
	Play_Background = LoadGraph("picture/Play_Background.png");//背景
	Lane = LoadGraph("picture/Lane.png");//ノーツを流すレーン
	Judge = LoadGraph("picture/Judge.png");//判定枠
	Notes[0] = LoadGraph("picture/ドン(大).png");//ドン
	Notes[1] = LoadGraph("picture/カッ(大).png");//カッ
	BrightD = LoadGraph("picture/BrightD.png");//赤く光る
	BrightK = LoadGraph("picture/BrightK.png");//青く光る
	/*
	Taiko = LoadGraph("");//画面に置く太鼓
	Split = LoadGraph("");//魂ゲージ
	Combo = LoadGraph("");//コンボ数
	*/
}
void Picture::Out(int x,int y, int draw) {
	DrawGraph(x,y,draw,TRUE);
};