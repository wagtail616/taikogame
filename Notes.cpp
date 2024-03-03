#include"Picture.h"
#include "Notes.h"

void Notes::Set(Picture picture) {
	picture.Out(this->x, y, picture.Notes);//�m�[�c
	DrawFormatString(x+25, y+125, GetColor(0, 0, 0), "�h��(��)");
};
void Notes::Move(Picture picture,GAMETIME gametime) {
	x -= NoteSpeed * gametime.GetDeltaTime();
}

void Notes::Setnumber(int i)
{
	number = i;
}

int Notes::Getnumber()
{
	return number;
}
