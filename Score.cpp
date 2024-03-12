#include <DxLib.h>
#include"score.h"
#include"Notes.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "Picture.h"

void Score::Load(){//Score
	std::ifstream ifs("Score/test.txt");
	if (ifs.fail()) {
		DrawFormatString(100, 100, GetColor(0, 0, 0), "Cannot open file");
	}
	else {
		std::string str;

		//BPM読み込む
		std::getline(ifs, str, ':');std::getline(ifs, str);
		std::stringstream bpm(str);
		bpm >> BPM;
		//1行だけ読み込んでタイミング設定
		複数行よみたい
		while (std::getline(ifs, str, ',')) {
			std::stringstream ss(str);
			if (str != "") {
				notes.push_back(note);
				notes[Notes_Number].SetTiming(timing);
				Notes_Number++;
			}
			リズムの定義をしっかりしたい
			timing+=60/BPM;
			
		}
	}
	Notes_Max = Notes_Number;
	Notes_Number = 0;
}

void Score::Out(Picture picture,GAMETIME Time) {
	for (j = 0; j < Notes_Number; j++) {
		notes[j].Move(picture, Time);
		DrawFormatString(50, 100+j*15, GetColor(0, 0, 0), "%f", notes[j].GetTiming());
	}

	DrawFormatString(25, 100, GetColor(0, 0, 0), "%f", BPM);

	
	//ノーツの間隔をあける条件式
	if (Notes_Number < Notes_Max) {
		if (notes[Notes_Number].GetTiming()< Time.GetElapsedTime()) {
			Notes_Number++;
		}
	}
}