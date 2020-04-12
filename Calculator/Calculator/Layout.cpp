#include "Layout.h"

Layout::Layout()
{
	_currentPartIndex = 0;
	_startRow = 0;
	_startCol = 0;
	_width = 0;
	_height = 0;
	_textColor = "default";
	_backColor = "default";
	_type = "layout";
	_frame = NULL;
	_highlight = false;
}

Layout::Layout(Layout* frame) : Layout::Layout()
{
	_frame = frame;
	frame->AddPart(this);
}


void Layout::MovePartIndexPrev()
{
	for (;;)
	{
		_currentPartIndex--;

		if (_currentPartIndex == -1)
			_currentPartIndex = _parts.size() - 1;

		if (GetPart()->_type != "layout")
			break;
	}
}

void Layout::MovePartIndexNext()
{
	for (;;)
	{
		_currentPartIndex++;

		if (_currentPartIndex == _parts.size())
			_currentPartIndex = 0;

		if (GetPart()->_type != "layout")
			break;
	}
}

Layout* Layout::GetPart()
{
	return _parts[_currentPartIndex];
}


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Layout Setters
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Set member of Layout.
void Layout::SetName(string name)
{
	_name = name;
}

void Layout::SetCoord(int startRow, int startCol)
{
	_startRow = startRow;
	_startCol = startCol;
}

void Layout::SetRelativeCoord(int relativeRow, int relativeCol)
{
	_startRow = _frame->GetStartRow() + relativeRow;
	_startCol = _frame->GetStartCol() + relativeCol;
}

void Layout::SetSize(int height, int width)
{
	_height = height;
	_width = width;
}

void Layout::SetColor(string&& textColor, string&& backColor)
{
	_textColor = textColor;
	_backColor = backColor;
}

void Layout::PushString(string str)
{
	_strings.emplace_back(str);
	_height = _strings.size();

	if (_width < str.size())
		_width = str.size();
}

void Layout::PushString(string str, string&& textColor, string&& backColor)
{
	_strings.emplace_back(str);
	_height = _strings.size();
	_textColor = textColor;
	_backColor = backColor;

	if (_width < str.size())
		_width = str.size();
}


void Layout::AddPart(Layout* part)
{
	_parts.emplace_back(part);

	if (part->_type == "layout")
		_currentPartIndex++;

	part->_frame = this;
}


void Layout::SetFirstPart()
{
	size_t index;

	for (index = 0; index < _frame->_parts.size() - 1; index++)
	{
		if (_frame->_parts[index]->GetName() == this->GetName())
			break;
	}

	_frame->_currentPartIndex = index;
	_frame->_currentPart = _frame->_parts[index];
}



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Layout Functions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


void Layout::Print()
{
	cinout.out(_startRow, _startCol, _strings, _textColor, _backColor);

	for (size_t number = 0; number < _parts.size(); number++)
		_parts[number]->Print();
}


void Layout::Erase()
{
	_eraser.resize(_width, ' ');

	for (size_t height = 0; height < _height; height++)
		cinout.out(_startRow + height, _startCol, _eraser);
}


/* return first string */
string Layout::Peek() const
{
	return _strings[0];
}


string Layout::Select()
{
	int command;
	DrawSelect();

	for (;;)
	{
		if ((command = cinout.inStatic()) == ARROW)
		{
			command = cinout.inStatic();

			EraseSelect();

			if (command == UP || command == RIGHT)	MovePartIndexPrev();
			else    /*  DOWN || LEFT   */			MovePartIndexNext();

			DrawSelect();
		}
		else if (command == ENTER)
		{
			EraseSelect();

			return GetPart()->GetName();
		}
		else if (command == ESC)
		{
			EraseSelect();
			return GetPrevName();
		}
	}
}


void Layout::DrawSelect()
{
	if (GetPart()->GetType() == "menu")			// Draw Arrow
	{
		cinout.drawSideArrow(GetPart()->GetStartRow(), GetPart()->GetStartCol(), GetPart()->Peek());






	}

	else if (GetPart()->GetType() == "button")	// Draw Highlight
	{


	
	}

	else if (GetPart()->GetType() == "screen")	// Draw Cursor Prompt
	{



	}
}

void Layout::EraseSelect()
{
	if (GetPart()->GetType() == "menu")			// Draw Arrow
	{
		cinout.eraseSideArrow(GetPart()->GetStartRow(), GetPart()->GetStartCol(), GetPart()->Peek());






	}

	else if (GetPart()->GetType() == "button")	// Draw Highlight
	{



	}

	else if (GetPart()->GetType() == "screen")	// Draw Cursor Prompt
	{



	}
}