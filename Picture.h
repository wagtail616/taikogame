#pragma once

class Picture {
public:
	//�^�C�g��
	int title;

	//�v���C���
	int Play_Background;//�w�i
	int Taiko;//��ʂɒu������
	int Lane;//�m�[�c�𗬂����[��
	int Judge;//����g
	int Notes[2] = {0,0};//�h���ƃJ�b
	int Split;//���Q�[�W
	int Combo;//�R���{��
	int BrightD, BrightK;//����G�t�F�N�g
	void Load();//������Picture.cpp
	void Out(int x, int y, int draw);//������picture.cpp
};

