#pragma once
#include"Picture.h"
class Key {
private:
	int Key[256];//キーが押されている秒数
public:
	int GetHitKey();


	void ScreenBright(Picture picture);

	bool GetKey(char key);


};