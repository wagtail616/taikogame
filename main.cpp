#include "DxLib.h"
#include "Picture.h"
#include "Title.h"
#include "Play.h"

#define SCREEN_WIDTH  1280
#define SCREEN_HIGHT  720

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	��ʕ\�����o�O��
	SetGraphMode(SCREEN_WIDTH,SCREEN_HIGHT,24);

	Picture picture{};
	picture.Load();//�S�摜�̓ǂݍ���

	//�^�C�g��
	TITLE title;
	title.Set(picture);
	WaitKey();				// �L�[���͑҂�
	//�v���C��
	PLAY play;
	play.Set(picture);

	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}