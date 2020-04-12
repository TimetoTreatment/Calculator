#pragma once
#include "Layout.h"

class Menu : public Layout
{
private:
	bool _isSelected;

public:
	Menu(Layout* frame);

	///////////
	/*  Set  */
	///////////

	void SetSelected();
	void SetNotSelected();
	bool isSelected();









};

