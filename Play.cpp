#include "Dxlib.h"
#include "Picture.h"
#include "Play.h"

void PLAY::Set(Picture picture) {

	picture.Out(0, 0, picture.Play_Background);//�Q�[���w�i
	picture.Out(0, 260, picture.Lane);//���[��
	picture.Out(0, 260, picture.Judge);//����g
};