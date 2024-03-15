#include "DxLib.h"
#include "GameTime.h"
#include "Picture.h"
#include "Title.h"
#include "Play.h"
#include "Score.h"

#define SCREEN_WIDTH  1280
#define SCREEN_HIGHT  720

//�����N�Q�l�Ƀt���[���Œ肷��
//https://dxlib.xsrv.jp/cgi/patiobbs/patio.cgi?mode=view&no=4799

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	{//��ʏ����ݒ�
		ChangeWindowMode(TRUE);//Window���[�h�ŋN��
		// �t���X�N���[�����[�h���̉𑜓x���[�h�����j�^�[�̍ő�𑜓x���g�p���郂�[�h�ɐݒ�
		SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_MAXIMUM);
		//��ʕ\�����o�O��
		SetGraphMode(SCREEN_WIDTH, SCREEN_HIGHT, 32);
	}

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}


	//�S�摜�̓ǂݍ���
	Picture picture{};
	picture.Load();
	
	//��ʂ̕`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//�^�C�g��
	Title title;
	title.Set(picture);
	ScreenFlip();
	WaitKey();// �L�[���͑҂�

	//���Ԃ̏����ݒ�
	GameTime Time;
	Time.Set();

	//�v���C�Ăяo��
	Play play;
	Score score;
	score.Load();//���[�h���A�m�[�c�ő�l�o��
	
	//�Q�[�����[�v
	while (!ProcessMessage() && (CheckHitKey(KEY_INPUT_ESCAPE) == 0)) {
		//��ʂ̏���
		ClearDrawScreen;

		play.Set(picture);
		//���Ԃ̃Z�b�g
		Time.Loop();
		
		//���ʂ̕\��
		score.Out(picture, Time);

		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}	
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}