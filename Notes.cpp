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
	//�m�[�c
	if(Notes_Type == 0){//�h��(��)
		picture.Out(this->x, y, picture.Notes[0]);
		DrawFormatString(x + 25, y + 125, GetColor(0, 0, 0), "�h��(��)");
	}
	if (Notes_Type == 1) {//�J�b(��)
		picture.Out(this->x, y, picture.Notes[1]);
		DrawFormatString(x + 25, y + 125, GetColor(0, 0, 0), "�J�b(��)");
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

