#include "Menu.h"

Menu::Menu(Layout* frame)
{
	_frame = frame;
	_isSelected = 0;
	_layoutType = "menu";
	frame->AddPart(this);
}



void Menu::SetSelected()
{
	_isSelected = 1;
}

void Menu::SetNotSelected()
{
	_isSelected = 0;
}

bool Menu::isSelected()
{
	return _isSelected;
}
