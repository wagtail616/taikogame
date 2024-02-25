#include "DxLib.h"
#include "Picture.h"
#include "Title.h"
#include "Play.h"

#define SCREEN_WIDTH  1280
#define SCREEN_HIGHT  720

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	画面表示がバグる
	SetGraphMode(SCREEN_WIDTH,SCREEN_HIGHT,24);

	Picture picture{};
	picture.Load();//全画像の読み込み

	//タイトル
	TITLE title;
	title.Set(picture);
	WaitKey();				// キー入力待ち
	//プレイ中
	PLAY play;
	play.Set(picture);

	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}