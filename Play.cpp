#include "Dxlib.h"
#include "Play.h"

void Play::Set(Picture picture) {

	picture.Out(0, 0, picture.Play_Background);//ƒQ[ƒ€”wŒi
	picture.Out(0, 260, picture.Lane);//ƒŒ[ƒ“
	picture.Out(0, 260, picture.Judge);//”»’è˜g
};

