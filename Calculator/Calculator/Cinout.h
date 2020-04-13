#pragma once
#include "console.h"
#include <iostream>
#include <windows.h>
#include <vector>
constexpr auto ARROW = 224;
constexpr auto UP = 72;
constexpr auto DOWN = 80;
constexpr auto LEFT = 77;
constexpr auto RIGHT = 75;
constexpr auto ENTER = 13;
constexpr auto ESC = 27;



using namespace std;



class Cinout
{
private:
	Console console;

public:


	int inStatic();
	int inDynamic();


	void out(int startRow, int startCol, string str, string textColor = "default", string backColor = "default");
	void out(int startRow, int startCol, vector<string> contents, string textColor = "default", string backColor = "default");
	void drawSideArrow(int startRow, int startCol, string str);
	void eraseSideArrow(int startRow, int startCol, string str);
	void drawHighlight(int startRow, int startCol, string str);
	void eraseHighlight(int startRow, int startCol, string str);
};

