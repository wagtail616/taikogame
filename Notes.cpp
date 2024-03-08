#include"Picture.h"
#include "Notes.h"

void Notes::Set(int i) {
	number = i;
	
}
void Notes::SetTiming(int timing) {
	this->timing = timing;
};

void Notes::Move(Picture picture,GAMETIME gametime) {
	picture.Out(this->x, y, picture.Notes);//ノーツ
	DrawFormatString(x + 25, y + 125, GetColor(0, 0, 0), "ドン(大)");
	x -= NoteSpeed * gametime.GetDeltaTime();
}


int Notes::Getnumber()
{
	return number;
}
double Notes::GetTiming() {
	return timing;
};