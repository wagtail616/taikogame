#include "Dxlib.h"
#include "Picture.h"

void Picture::Load() {
	//�^�C�g��
	title = LoadGraph("picture/Title.png");
	
	//�v���C���
	Play_Background = LoadGraph("picture/Play_Background.png");//�w�i
	Lane = LoadGraph("picture/Lane.png");//�m�[�c�𗬂����[��
	Judge = LoadGraph("picture/Judge.png");//����g
	Notes = LoadGraph("picture/�h��(��).png");//�h���ƃJ�b
	/*
	Taiko = LoadGraph("");//��ʂɒu������
	Split = LoadGraph("");//���Q�[�W
	Combo = LoadGraph("");//�R���{��
	*/
}
void Picture::Out(int x,int y, int draw) {
	DrawGraph(x,y,draw,TRUE);
};