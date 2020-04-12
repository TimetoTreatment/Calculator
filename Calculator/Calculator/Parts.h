#pragma once
#include "Layout.h"
class Parts : public Layout
{
private:






public:
	Parts(Layout* frame)
	{
		_highlight = false;
		_frame = frame;
		_type = "parts";
		frame->AddPart(this);




	}







};

