#pragma once
#include"Picture.h"
class Key {
private:
	int Key[256];//ƒL[‚ª‰Ÿ‚³‚ê‚Ä‚¢‚é•b”
public:
	int GetHitKey();


	void ScreenBright(Picture picture);

	bool GetKey(char key);


};