#pragma once
#include "GameTime.h"
#include "Picture.h"
#include "Notes.h"
#include <vector>
class Score {
private:
	double BPM = 0;
	double minits = 60;
	int j;
	int Notes_Number=0;
	double timing = 1; 
	int Notes_Max=0;
	std::vector<Notes>notes;
	Notes note;
public:
	void Load();
	void Out(Picture picture, GameTime Time);
};

