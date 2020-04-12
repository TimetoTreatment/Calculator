#pragma once
#include "Layout.h"
#include "Button.h"
#include "Screen.h"
#include "Menu.h"
#include "State.h"


class LayoutFactory
{
private:
	State state;



public:
	/* ��ǰ */
	Layout* simpleCalc(Layout* frame);

	/* ������ */
	Layout* mainFrame(int startRow = 0, int startCol = 0);
	Layout* mainMenuPage(int startRow, int startCol);
	Layout* optionPage();
	Layout* exitPage();
	Layout* startCalcPage(int startRow, int startCol);
};

