#pragma once
class Notes{
private:
	int number[100]{};//ノーツ番号
	int x = 1280, y = 260;//ノーツ位置
public:
	void Set(Picture picture);
	void Move(Picture picture);
};
