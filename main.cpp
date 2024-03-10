#include "DxLib.h"
#include "GameTime.h"
#include "Picture.h"
#include "Title.h"
#include "Play.h"
#include "Notes.h"
#include "score.h"
#include "vector"
#include <iostream>

#define SCREEN_WIDTH  1280
#define SCREEN_HIGHT  720

//リンク参考にフレーム固定する
//https://dxlib.xsrv.jp/cgi/patiobbs/patio.cgi?mode=view&no=4799

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
	//時間の初期設定
	GAMETIME Time;
	Time.Set();
	//全画像の読み込み
	Picture picture{};
	picture.Load();
	//画面の描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	//タイトル
	TITLE title;
	title.Set(picture);
	ScreenFlip();
	WaitKey();				// キー入力待ち
	//プレイ中
	//ループ中の処理考える
	PLAY play;
	Score score;
	Notes note;
	std::vector<Notes>notes;
	int i=0, j=0;
	std::vector<std::string> result;

	{//Score
		std::ifstream ifs("Score/test.txt");
		if (ifs.fail()) {
			DrawFormatString(100, 100, GetColor(0, 0, 0), "Cannot open file");
		}
		else {
			std::string str;
			i = 0, j = 0;
			while (std::getline(ifs, str,',')) {
				std::stringstream ss(str);
				result.push_back(str);
				//if (str != "") {
					//note.Set(i);
					notes.push_back(note);
					notes[i].SetTiming(i);
					i++;
				//}
				j++;

			}
		}

	}
	int Notes_Max = i;

	while (!ProcessMessage() && (CheckHitKey(KEY_INPUT_ESCAPE) == 0)) {
		//画面の消去
		ClearDrawScreen;

		play.Set(picture);
		//時間のセット
		Time.Loop();
		
		/*
		for (auto& note:notes) {
			note.Set(picture);
			note.Move(picture, Time);
		}*/
		
		for (j = 0; j < i;j++) {
			notes[j].Move(picture, Time);
		}

		//ノーツの間隔をあける
		if (i < Notes_Max - 1) {
			if (notes[i].GetTiming()+1<Time.GetElapsedTime()) {
				i++;
			}
		}
		j = 0;
		for (std::string s:result) {
			DrawFormatString(250 + j * 5, 0, GetColor(0, 0, 0),s.c_str());
			j++;
		}
		// 裏画面の内容を表画面に反映
		ScreenFlip();
	}	
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}