#ifndef PICTURE_H_
#define PICTURE_H_

class Picture {
public:
	//タイトル
	int title;

	//プレイ画面
	int Play_Background;//背景
	int taiko;//画面に置く太鼓
	int lane;//ノーツを流すレーン
	int notes;//ドンとカッ
	int judge;//判定枠
	int split;//魂ゲージ
	int combo;//コンボ数

	void Load();//実装はPicture.cpp
	void Out(int x, int y, int draw);//実装はpicture.cpp
};
#endif 