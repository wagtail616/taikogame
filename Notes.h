#pragma once
#include"GameTime.h"
#include"Picture.h"
class Notes{
private:
	int number = 0;//�m�[�c�ԍ�
	int Notes_Type = 0;//�h����J�b�̎��
	double timing=0;//�^�C�~���O
	float x = 1280;int y = 260;//�m�[�c�ʒu
	float NoteSpeed = 200.0f;

public:
	void Set(int i);
	void SetType(int i);
	void SetTiming(double timing);
	void Move(Picture picture,GameTime gametime);
	int Getnumber();
	double GetTiming();
};

