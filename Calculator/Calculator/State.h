#pragma once
#include <string>

using namespace std;

class State
{
private:
	static int _maxRow;
	static int _maxCol;
	static int _defaultRow;
	static int _defaultCol;
	static char _operator;
	static string _mode;

public:


	int getMaxRow();
	int getMaxCol();
	int getDefaultRow();
	int getDefaultCol();
	char getOperator();
	string getMode();

	void setMaxRow(int maxRow);
	void setMaxCol(int maxCol);
	void setDefaultCoord(int defaultRow, int defaultCol);
	void setOperator(int oper);
	void setMode(int mode);
};

