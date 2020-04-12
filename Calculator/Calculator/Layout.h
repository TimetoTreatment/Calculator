//
// Made by (CE) TimetoTreatment.
//
//
// Layout Header.
//
// Declaration of the Layout Class.
//

#pragma once

#include <string>
#include <vector>
#include "Cinout.h"

using namespace std;


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Define DATA type and ____ structure
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

// ~def ___ DATA;
typedef int DATA;

typedef struct _zxcv
{
	DATA* ar;
	int top;
	int max;

} zxcv;


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Layout Class
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

class Layout
{
private:
	string _name;
	vector<Layout*> _parts;
	int _currentPartIndex;
	Layout* _currentPart;
	string _eraser;
	Cinout cinout;
	void MovePartIndexPrev();
	void MovePartIndexNext();
	Layout* GetPart();
	string _prevName;

protected:
	int _startRow;		// Left top row of Layout
	int _startCol;		// Left top col of Layout
	size_t _height;
	size_t _width;
	string _textColor;
	string _backColor;
	vector<string> _strings;
	string _type;
	Layout* _frame;
	bool _highlight;

	void DrawSelect();

	void EraseSelect();

public:
	Layout();
	Layout(Layout* frame);

	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Layout Setters
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// Set member of Layout.

	void SetName(string name);
	void SetPrevName(string prevName) { _prevName = prevName; }
	void SetCoord(int startRow, int startCol);
	void SetRelativeCoord(int relativeRow, int relativeCol);
	void SetSize(int height, int width);
	void SetColor(string&& textColor, string&& backColor = "default");
	void PushString(string str);
	void PushString(string str, string&& textColor, string&& backColor = "default");
	void AddPart(Layout* part);
	void SetFirstPart();


	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Layout Getters
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// Get member of Layout.

	string GetName() const { return _name; }
	string GetPrevName() const { return _prevName; }
	int GetStartRow() const { return _startRow; }
	int GetStartCol() const { return _startCol; }
	Layout* GetFrame() const { return _frame; }
	string GetType() const { return _type; }

	/* Return first string */
	string Peek() const;


	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Layout Functions
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	/* Print Layout to console */
	void Print();

	/* Erase Layout from console */
	void Erase();

	/* Iterate over Menus, Buttons, Screens */
	string Select();


};