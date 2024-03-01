#include"Picture.h"
#include "Notes.h"

void Notes::Set(Picture picture) {
	picture.Out(this->x, y, picture.Notes);//ノーツ
};
void Notes::Move(Picture picture,GAMETIME gametime) {
	x -= NoteSpeed * gametime.GetDeltaTime();
	picture.Out(x, y, picture.Notes);//ノーツ
}