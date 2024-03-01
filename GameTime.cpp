#include "GameTime.h"

void GAMETIME::Set()
{
	//初期値
	Time = GetNowHiPerformanceCount();//システム時間取得
	DeltaTime = 0.000001f;//経過時間の初期値
	//FPS計測関係の初期値
	FPSCheckTime = GetNowHiPerformanceCount();
	FPS = 0;
	FPSCounter = 0;
}

void GAMETIME::Loop()
{
	// FPSの描画
	DrawFormatString(0, 0, GetColor(0, 0, 0), "FPS:%d", FPS);
	//現在のシステム時刻
	NowTime = GetNowHiPerformanceCount(); 
	//前回取得した時間からの経過時間を秒に変換してセット
	DeltaTime =(NowTime-Time)/ 1000000.0f;
	//今回取得した時間を保存
	Time = NowTime;

	FPSCounter++;
	if (NowTime - FPSCheckTime > 1000000) {
		FPS = FPSCounter;
		FPSCounter = 0;
		FPSCheckTime = NowTime;
	}
}

float GAMETIME::GetDeltaTime()
{
	return DeltaTime;
}
