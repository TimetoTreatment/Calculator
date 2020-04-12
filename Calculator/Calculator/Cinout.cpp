#include "Cinout.h"
#include <conio.h>


using namespace std;



int Cinout::inDynamic()
{
	if (_kbhit())
	{
		return _getch();
	}

	return 0;
}


int Cinout::inStatic()
{
	return _getch();
}


void Cinout::out(int startRow, int startCol, string str, string textColor, string backColor)
{
	console.setColor(textColor, backColor);
	console.setCursorPosition(startRow, startCol);

	cout << str;

	console.setColorDefault();
	console.setCursorPositionDefault();
}





void Cinout::out(int startRow, int startCol, vector<string> contents, string textColor, string backColor)
{
	if (contents.empty())
		return;

	console.setColor(textColor, backColor);

	for (size_t row = 0; row < contents.size() - 1; row++)
	{
		console.setCursorPosition(startRow + row, startCol);
		cout << contents[row] << endl;
	}
	console.setCursorPosition(startRow + contents.size() - 1, startCol);
	cout << contents.back();

	console.setColorDefault();
	console.setCursorPositionDefault();
}

void Cinout::drawSideArrow(int startRow, int startCol, string str)
{
	console.setColor("white");
	console.setCursorPosition(startRow, startCol - 4);
	cout << "->";
	console.setCursorPosition(startRow, startCol + str.size() + 2);
	cout << "<-";
	console.setCursorPositionDefault();
	console.setCursorPositionDefault();
}


void Cinout::eraseSideArrow(int startRow, int startCol, string str)
{
	console.setCursorPosition(startRow, startCol - 4);
	cout << "  ";
	console.setCursorPosition(startRow, startCol + str.size() + 2);
	cout << "  ";
	console.setCursorPositionDefault();
	console.setCursorPositionDefault();
}