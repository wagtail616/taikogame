#include <DxLib.h>
#include"Score.h"
#include <string>
#include <fstream>
#include <sstream>

void Score::Load(){//Score
	std::ifstream ifs("Score/test.txt");
	int Notes_Number=0;
	Notes note;

	if (ifs.fail()) {
		DrawFormatString(100, 100, GetColor(0, 0, 0), "Cannot open file");
	}
	else {
		//std::string str;
		
		//BPM読み込む
		std::getline(ifs, str, ':');std::getline(ifs, str);
		std::stringstream bpm(str);
		bpm >> BPM;
		//1行だけ読み込んでタイミング設定
		
	/*	while (std::getline(ifs, str)) {
			std::istringstream ss(str);
			std::string s;
			while (ss >> s) {

			}
		}*/
	//https://maku77.github.io/cpp/string/split.html


		//改行を認識しつつ複数回最後まで処理
		while (!ifs.eof()) {
			while (std::getline(ifs, str, ',')) {
				std::stringstream ss(str);

				if (str != "") {
					notes.push_back(note);
					notes[Notes_Number].SetTiming(timing);
					Notes_Number++;
				}
				//リズムの定義をしっかりしたい
				timing += 60 / BPM;
				if (str == "\0") {
					break;
				}
			}
		}
	}
	Notes_Max = Notes_Number;
}

void Score::Out(Picture picture,GameTime Time) {
	for (j = 0; j < Notes_Number; j++) {
		notes[j].Move(picture, Time);
		DrawFormatString(150, 100 + j * 15, GetColor(0, 0, 0), "%f", notes[j].GetTiming());
		
		DrawFormatString(300, 100, GetColor(0, 0, 0), "%s", str.c_str());
	}

	DrawFormatString(25, 100, GetColor(0, 0, 0), "%f", BPM);
	DrawFormatString(25, 200, GetColor(0, 0, 0), "%d", Notes_Number);

	
	//ノーツの間隔をあける条件式
	if (Notes_Number < Notes_Max-1) {
		if (notes[Notes_Number].GetTiming()< Time.GetElapsedTime()) {
			Notes_Number++;
		}
	}
}