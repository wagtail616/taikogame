#pragma once
#include"GameTime.h"
class Notes{
private:
	int number = 0;//ノーツ番号
	double timing=0;//タイミング
	float x = 1280;int y = 260;//ノーツ位置
	float NoteSpeed = 200.0f;

public:
	void Set(int i);
	void SetTiming(double timing);
	void Move(Picture picture,GAMETIME gametime);
	int Getnumber();
	double GetTiming();
};
