#include "Dxlib.h"
#include "Picture.h"

void Picture::Load() {
	//�^�C�g��
	title = LoadGraph("picture/Title.png");
	/*
	//�v���C���
	Play_background  = LoadGraph("");//�w�i
	taiko = LoadGraph("");//��ʂɒu������
	lane  = LoadGraph("");//�m�[�c�𗬂����[��
	notes = LoadGraph("");//�h���ƃJ�b
	judge = LoadGraph("");//����g
	split = LoadGraph("");//���Q�[�W
	combo = LoadGraph("");//�R���{��
	*/
}
void Out(int x,int y, int draw) {
	DrawGraph(x,y,draw,TRUE);
};