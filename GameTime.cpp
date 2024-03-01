#include "GameTime.h"

void GAMETIME::Set()
{
	//�����l
	Time = GetNowHiPerformanceCount();//�V�X�e�����Ԏ擾
	DeltaTime = 0.000001f;//�o�ߎ��Ԃ̏����l
	//FPS�v���֌W�̏����l
	FPSCheckTime = GetNowHiPerformanceCount();
	FPS = 0;
	FPSCounter = 0;
}

void GAMETIME::Loop()
{
	// FPS�̕`��
	DrawFormatString(0, 0, GetColor(0, 0, 0), "FPS:%d", FPS);
	//���݂̃V�X�e������
	NowTime = GetNowHiPerformanceCount(); 
	//�O��擾�������Ԃ���̌o�ߎ��Ԃ�b�ɕϊ����ăZ�b�g
	DeltaTime =(NowTime-Time)/ 1000000.0f;
	//����擾�������Ԃ�ۑ�
	Time = NowTime;

	FPSCounter++;
	if (NowTime - FPSCheckTime > 1000000) {
		FPS = FPSCounter;
		FPSCounter = 0;
		FPSCheckTime = NowTime;
	}
}

float GAMETIME::GetDeltaTime()
{
	return DeltaTime;
}
