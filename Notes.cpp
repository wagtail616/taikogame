#include "Notes.h"

void Notes::Set(int i) {
	number = i;
}

void Notes::SetType(int i) {
	Notes_Type = i;
}

void Notes::SetTiming(double timing) {
	this->timing = timing;
};

void Notes::Move(Picture picture,GameTime gametime) {
	//ノーツ
	if(Notes_Type == 0){//ドン(大)
		picture.Out(this->x, y, picture.Notes[0]);
		DrawFormatString(x + 25, y + 125, GetColor(0, 0, 0), "ドン(大)");
	}
	if (Notes_Type == 1) {//カッ(大)
		picture.Out(this->x, y, picture.Notes[1]);
		DrawFormatString(x + 25, y + 125, GetColor(0, 0, 0), "カッ(大)");
	}
	x -= NoteSpeed * gametime.GetDeltaTime();
}


int Notes::Getnumber()
{
	return number;
}
double Notes::GetTiming() {
	return timing;
};

