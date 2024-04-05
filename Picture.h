#pragma once

class Picture {
public:
	//タイトル
	int title;

	//プレイ画面
	int Play_Background;//背景
	int Taiko;//画面に置く太鼓
	int Lane;//ノーツを流すレーン
	int Judge;//判定枠
	int Notes[2] = {0,0};//ドンとカッ
	int Split;//魂ゲージ
	int Combo;//コンボ数
	int BrightD, BrightK;//光るエフェクト
	void Load();//実装はPicture.cpp
	void Out(int x, int y, int draw);//実装はpicture.cpp
};

