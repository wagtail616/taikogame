#include "DxLib.h"
#include "Picture.h"
#include "Title.h"
#include "Play.h"
#include "Notes.h"

#define SCREEN_WIDTH  1280
#define SCREEN_HIGHT  720

�����N�Q�l�Ƀt���[���Œ肷��
https://dxlib.xsrv.jp/cgi/patiobbs/patio.cgi?mode=view&no=4799

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

	Picture picture{};
	picture.Load();//�S�摜�̓ǂݍ���

	//�^�C�g��
	TITLE title;
	title.Set(picture);
	WaitKey();				// �L�[���͑҂�
	//�v���C��
	//���[�v���̏����l����
	PLAY play;
	Notes notes;
	while (!ProcessMessage() && (CheckHitKey(KEY_INPUT_ESCAPE) == 0)) {
	play.Set(picture);
	notes.Set(picture);
	notes.Move(picture);
	ClearDrawScreen;
	}	
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}