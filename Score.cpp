#include <DxLib.h>
#include"Score.h"
#include <string>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <iostream>
#include <string>

void Score::Load(){//Score
	std::ifstream ifs("Score/test.txt");
	int Notes_Number=0;
	Notes note;

	if (ifs.fail()) {
		DrawFormatString(100, 100, GetColor(0, 0, 0), "Cannot open file");
	}
	else {
		//std::string str;
		
		//BPM�ǂݍ���
		std::getline(ifs, str, ':');std::getline(ifs, str);
		std::stringstream bpm(str);
		bpm >> BPM;
		//1�s�����ǂݍ���Ń^�C�~���O�ݒ�
		int i = 0;
			while (std::getline(ifs, str)) {
				std::replace(str.begin(), str.end(), ',',' ');
				std::istringstream ss(str);
				std::string s;
				split = 0;
				while (ss >> s) {
					if (s == "1") {
						notes.push_back(note);
						notes[Notes_Number].SetTiming(timing);
						Notes_Number++;
					}
					//���Y���̒�`���������肵����
						timing += 60 / BPM;
						split++;
				}
				for (; i < Notes_Number;i++) {
					notes[i].SetTiming(notes[i].GetTiming() / split);
				}
				i = Notes_Number;

			}
	//https://maku77.github.io/cpp/string/split.html


		//���s��F����������Ō�܂ŏ���
		/*while (!ifs.eof()) {
			while (std::getline(ifs, str, ',')) {
				std::stringstream ss(str);

				if (str != "") {
					notes.push_back(note);
					notes[Notes_Number].SetTiming(timing);
					Notes_Number++;
				}
				//���Y���̒�`���������肵����
				timing += 60 / BPM;

				if (str == "\n") {
					break;
				}

			}
		}*/
	}
	Notes_Max = Notes_Number;
}

void Score::Out(Picture picture,GameTime Time) {
	for (j = 0; j < Notes_Number; j++) {
		notes[j].Move(picture, Time);
		DrawFormatString(150, 100 + j * 15, GetColor(0, 0, 0), "%f", notes[j].GetTiming());
		
	}


	
	//�m�[�c�̊Ԋu�������������
	if (Notes_Number < Notes_Max) {
		if (notes[Notes_Number].GetTiming()< Time.GetElapsedTime()) {
			Notes_Number++;
		}
	}
}