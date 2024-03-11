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
		while (std::getline(ifs, str, ',')) {
			std::stringstream ss(str);
			if (str != "") {
				notes.push_back(note);
				notes[Notes_Number].SetTiming(timing);
				Notes_Number++;
			}
			timing++;

		}
	}
	Notes_Max = Notes_Number;
	Notes_Number = 0;
}

void Score::Out(Picture picture,GAMETIME Time) {
	for (j = 0; j < Notes_Number; j++) {
		notes[j].Move(picture, Time);
		DrawFormatString(100, 100 + j * 10, GetColor(0, 0, 0), "%f", notes[j].GetTiming());
	}

	DrawFormatString(25, 100, GetColor(0, 0, 0), "%d", Notes_Max);
	DrawFormatString(25, 200, GetColor(0, 0, 0), "%d", Notes_Number);

	‚È‚¨‚Á‚½‚ ‚ ‚ ‚ ‚ 
	//ƒm[ƒc‚ÌŠÔŠu‚ð‚ ‚¯‚éðŒŽ®
	if (Notes_Number < Notes_Max) {
		if (notes[Notes_Number].GetTiming()< Time.GetElapsedTime()) {
			Notes_Number++;
		}
	}
}