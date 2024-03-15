#include "DxLib.h"
#include "GameTime.h"
#include "Picture.h"
#include "Title.h"
#include "Play.h"
#include "Score.h"

#define SCREEN_WIDTH  1280
#define SCREEN_HIGHT  720

//リンク参考にフレーム固定する
//https://dxlib.xsrv.jp/cgi/patiobbs/patio.cgi?mode=view&no=4799

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	{//画面初期設定
		ChangeWindowMode(TRUE);//Windowモードで起動
		// フルスクリーンモード時の解像度モードをモニターの最大解像度を使用するモードに設定
		SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_MAXIMUM);
		//画面表示がバグる
		SetGraphMode(SCREEN_WIDTH, SCREEN_HIGHT, 32);
	}

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}


	//全画像の読み込み
	Picture picture{};
	picture.Load();
	
	//画面の描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	//タイトル
	Title title;
	title.Set(picture);
	ScreenFlip();
	WaitKey();// キー入力待ち

	//時間の初期設定
	GameTime Time;
	Time.Set();

	//プレイ呼び出し
	Play play;
	Score score;
	score.Load();//ロードしつつ、ノーツ最大値出力
	
	//ゲームループ
	while (!ProcessMessage() && (CheckHitKey(KEY_INPUT_ESCAPE) == 0)) {
		//画面の消去
		ClearDrawScreen;

		play.Set(picture);
		//時間のセット
		Time.Loop();
		
		//譜面の表示
		score.Out(picture, Time);

		// 裏画面の内容を表画面に反映
		ScreenFlip();
	}	
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}