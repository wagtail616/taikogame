#include "Dxlib.h"
#include "Picture.h"

void Picture::Load() {
	//�^�C�g��
	title = LoadGraph("picture/Title.png");
	
	//�v���C���
	Play_Background = LoadGraph("picture/Play_Background.png");//�w�i
	Lane = LoadGraph("picture/Lane.png");//�m�[�c�𗬂����[��
	/*
	Taiko = LoadGraph("");//��ʂɒu������
	Notes = LoadGraph("");//�h���ƃJ�b
	Judge = LoadGraph("");//����g
	Split = LoadGraph("");//���Q�[�W
	Combo = LoadGraph("");//�R���{��
	*/
}
void Picture::Out(int x,int y, int draw) {
	DrawGraph(x,y,draw,TRUE);
};