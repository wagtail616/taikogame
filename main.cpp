#include "DxLib.h"
#include "Picture.h"
#include "Title.h"
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	Picture picture{};
	picture.Load();//�S�摜�̓ǂݍ���

	TITLE title;
	title.Set(picture);

	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}