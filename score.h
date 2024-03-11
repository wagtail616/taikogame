#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "DxLib.h"
#include "GameTime.h"
#include "Picture.h"
#include "Title.h"
#include "Play.h"
#include "Notes.h"
#include "score.h"
class Score {
private:
	int j;
	int Notes_Number=0;
	int timing = 0; 
	int Notes_Max=0;
	std::vector<Notes>notes;
	Notes note;
public:
	void Load();
	void Out(Picture picture, GAMETIME Time);
};