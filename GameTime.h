#pragma once
#include"Dxlib.h"
class GAMETIME {
private:
	LONGLONG NowTime;     //���ݎ���
	LONGLONG BeforeTime;  //�V�X�e������
	LONGLONG Time;        //�J�n����
	
	double ElapsedTime = 0;

	float x;              //���W
	float add;            //�ړ����x
	float DeltaTime;      //�o�ߎ���
	LONGLONG FPSCheckTime;//FPS�v���֌W
	int FPS = 0;          //FPS�v���֌W
	int FPSCounter = 0;   //FPS�v���֌W
public:
	void Set();
	void Loop();
	float GetDeltaTime();
	float GetElapsedTime();
};