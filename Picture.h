#ifndef PICTURE_H_
#define PICTURE_H_

class Picture {
public:
	//�^�C�g��
	int title;

	//�v���C���
	int Play_Background;//�w�i
	int taiko;//��ʂɒu������
	int lane;//�m�[�c�𗬂����[��
	int notes;//�h���ƃJ�b
	int judge;//����g
	int split;//���Q�[�W
	int combo;//�R���{��

	void Load();//������Picture.cpp
	void Out(int x, int y, int draw);//������picture.cpp
};
#endif 