#include "Dxlib.h"
#include "Picture.h"

void Picture::Load() {
	//�^�C�g��
	title = LoadGraph("picture/Title.png");
	
	//�v���C���
	Play_Background = LoadGraph("picture/Play_Background.png");//�w�i
	Lane = LoadGraph("picture/Lane.png");//�m�[�c�𗬂����[��
	Judge = LoadGraph("picture/Judge.png");//����g
	Notes[0] = LoadGraph("picture/�h��(��).png");//�h��
	Notes[1] = LoadGraph("picture/�J�b(��).png");//�J�b
	/*
	Taiko = LoadGraph("");//��ʂɒu������
	Split = LoadGraph("");//���Q�[�W
	Combo = LoadGraph("");//�R���{��
	*/
}
void Picture::Out(int x,int y, int draw) {
	DrawGraph(x,y,draw,TRUE);
};