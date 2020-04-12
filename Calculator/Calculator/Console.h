#pragma once
#include <windows.h>
#include <iostream>
#include "state.h"

using namespace std;

class Console
{
private:
	State state;
	static HANDLE hConsole;

	/* Change Color Name to Integer */
	int colorNameToNumber(string& colorName);

public:
	/* Set Console Cursor Position */
	void setCursorPosition(int row, int col);

	/* Set Console Cursor Position to Dafault */
	void setCursorPositionDefault();


	/* Clear CMD Console */
	void clearConsole();

	/* Set Text Color */
	void setColor(string foreground = "default", string background = "default");
	void setColorDefault();
};
