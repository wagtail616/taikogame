#include"Picture.h"
#include "Notes.h"

void Notes::Set(Picture picture) {
	picture.Out(this->x, y, picture.Notes);//�m�[�c
};
void Notes::Move(Picture picture) {
	x--;
	picture.Out(x, y, picture.Notes);//�m�[�c
}