#pragma once
#include"Picture.h"
class Key {
private:
	int Key[256];//�L�[��������Ă���b��
public:
	int GetHitKey();


	void ScreenBright(Picture picture);

	bool GetKey(char key);


};