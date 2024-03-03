#pragma once
#include"GameTime.h"
class Notes{
private:
	int number=0;//ノーツ番号
	float x = 1280;int y = 260;//ノーツ位置
	float NoteSpeed = 200.0f;

public:
	void Set(Picture picture);
	void Move(Picture picture,GAMETIME gametime);
	void Setnumber(int i);
	int Getnumber();
};
