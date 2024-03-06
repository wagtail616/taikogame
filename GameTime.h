#pragma once
#include"Dxlib.h"
class GAMETIME {
private:
	LONGLONG NowTime;     //現在時刻
	LONGLONG BeforeTime;  //システム時間
	LONGLONG Time;        //開始時間
	
	double ElapsedTime = 0;

	float x;              //座標
	float add;            //移動速度
	float DeltaTime;      //経過時間
	LONGLONG FPSCheckTime;//FPS計測関係
	int FPS = 0;          //FPS計測関係
	int FPSCounter = 0;   //FPS計測関係
public:
	void Set();
	void Loop();
	float GetDeltaTime();
	float GetElapsedTime();
};