#include "state.h"



////////////////////////////
////////*  Option  *////////
////////////////////////////
int State::_maxRow = 29;
int State::_maxCol = 120;
int State::_defaultRow = 29;
int State::_defaultCol = 1;
char State::_operator = 30;
string State::_mode = "basic";


///////////////////////////
/////////*  Set  */////////
///////////////////////////
int State::getMaxRow()
{
	return _maxRow;
}

int State::getMaxCol()
{
	return _maxCol;
}

int State::getDefaultRow()
{
	return _defaultRow;
}

int State::getDefaultCol()
{
	return _defaultCol;
}

char State::getOperator()
{
	return _operator;
}

string State::getMode()
{
	return _mode;
}


///////////////////////////
/////////*  Get  */////////
///////////////////////////
void State::setMaxRow(int maxRow)
{
	_maxRow = maxRow;
}

void State::setMaxCol(int maxCol)
{
	_maxCol = maxCol;
}

void State::setDefaultCoord(int defaultRow, int defaultCol)
{
	_defaultRow = defaultRow;
	_defaultCol = defaultCol;
}

void State::setOperator(int oper)
{
	_operator = oper;
}

void State::setMode(int mode)
{
	_mode = mode;
}