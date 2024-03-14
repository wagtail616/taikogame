#include "Notes.h"

void Notes::Set(int i) {
	number = i;
	
}
void Notes::SetTiming(double timing) {
	this->timing = timing;
};

void Notes::Move(Picture picture,GameTime gametime) {
	picture.Out(this->x, y, picture.Notes);//ƒm[ƒc
	DrawFormatString(x + 25, y + 125, GetColor(0, 0, 0), "ƒhƒ“(‘å)");
	x -= NoteSpeed * gametime.GetDeltaTime();
}


int Notes::Getnumber()
{
	return number;
}
double Notes::GetTiming() {
	return timing;
};

