#pragma once
#include"GameTime.h"
#include"Picture.h"
class Notes{
private:
	int number = 0;//ノーツ番号
	int Notes_Type = 0;//ドンやカッの種類
	double timing=0;//タイミング
	float x = 1280;int y = 260;//ノーツ位置
	float NoteSpeed = 200.0f;

public:
	void Set(int i);
	void SetType(int i);
	void SetTiming(double timing);
	void Move(Picture picture,GameTime gametime);
	int Getnumber();
	double GetTiming();
};

