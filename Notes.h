#pragma once
#include"GameTime.h"
class Notes{
private:
	int number = 0;//�m�[�c�ԍ�
	double timing=0;//�^�C�~���O
	float x = 1280;int y = 260;//�m�[�c�ʒu
	float NoteSpeed = 200.0f;

public:
	void Set(int i);
	void SetTiming(double timing);
	void Move(Picture picture,GAMETIME gametime);
	int Getnumber();
	double GetTiming();
};
