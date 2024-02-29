#include "DxLib.h"
#include "Picture.h"
#include "Title.h"
#include "Play.h"
#include "Notes.h"

#define SCREEN_WIDTH  1280
#define SCREEN_HIGHT  720

リンク参考にフレーム固定する
https://dxlib.xsrv.jp/cgi/patiobbs/patio.cgi?mode=view&no=4799

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);//Windowモードで起動
	// フルスクリーンモード時の解像度モードをモニターの最大解像度を使用するモードに設定
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_MAXIMUM);
	//画面表示がバグる
	SetGraphMode(SCREEN_WIDTH, SCREEN_HIGHT, 32);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	Picture picture{};
	picture.Load();//全画像の読み込み

	//タイトル
	TITLE title;
	title.Set(picture);
	WaitKey();				// キー入力待ち
	//プレイ中
	//ループ中の処理考える
	PLAY play;
	Notes notes;
	while (!ProcessMessage() && (CheckHitKey(KEY_INPUT_ESCAPE) == 0)) {
	play.Set(picture);
	notes.Set(picture);
	notes.Move(picture);
	ClearDrawScreen;
	}	
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}