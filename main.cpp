#include "DxLib.h"
#include "GameTime.h"
#include "Picture.h"
#include "Title.h"
#include "Play.h"
#include "Notes.h"
#include "vector"

#define SCREEN_WIDTH  1280
#define SCREEN_HIGHT  720

//�����N�Q�l�Ƀt���[���Œ肷��
//https://dxlib.xsrv.jp/cgi/patiobbs/patio.cgi?mode=view&no=4799

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);//Window���[�h�ŋN��
	// �t���X�N���[�����[�h���̉𑜓x���[�h�����j�^�[�̍ő�𑜓x���g�p���郂�[�h�ɐݒ�
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_MAXIMUM);
	//��ʕ\�����o�O��
	SetGraphMode(SCREEN_WIDTH, SCREEN_HIGHT, 32);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	//���Ԃ̏����ݒ�
	GAMETIME Time;
	Time.Set();
	//�S�摜�̓ǂݍ���
	Picture picture{};
	picture.Load();
	//��ʂ̕`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//�^�C�g��
	TITLE title;
	title.Set(picture);
	ScreenFlip();
	WaitKey();				// �L�[���͑҂�
	//�v���C��
	//���[�v���̏����l����
	PLAY play;
	Notes note;
	std::vector<Notes>notes;
	int Notes_Max = 100;
	int i;
	int j;
	for (i = 0; i <100;i++) {
		note.Set(i);
		notes.push_back(note);
	}
	i = 0;
	j = 0;
	while (!ProcessMessage() && (CheckHitKey(KEY_INPUT_ESCAPE) == 0)) {
		//��ʂ̏���
		ClearDrawScreen;

		play.Set(picture);
		//���Ԃ̃Z�b�g
		Time.Loop();
		
		/*
		for (auto& note:notes) {
			note.Set(picture);
			note.Move(picture, Time);
		}*/
		
		for (j = 0; j < i;j++) {
			notes[j].Move(picture, Time);
		}

		//�m�[�c�̊Ԋu��������
		if (i < Notes_Max - 1) {
			if ((float)(i+1)/2<Time.GetElapsedTime()) {
				i++;
			}
		}
		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}	
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}