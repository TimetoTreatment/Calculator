#include <iostream>
#include <time.h>
#include "LayoutFactory.h"


using namespace std;



int main(void)
{
	srand((unsigned int)time(NULL));
	LayoutFactory layoutFactory;
	string currentMenu;


	Layout* mainFrame = layoutFactory.mainFrame(0, 0);
	Layout* mainMenuPage = layoutFactory.mainMenuPage(2, 47);
	Layout* startCalcPage = layoutFactory.startCalcPage(4, 4);
	

	mainFrame->Print();
	currentMenu = "mainMenuPage";
	
	for (;;)
	{
		if (currentMenu == "mainMenuPage")
		{
			mainMenuPage->Print();
			currentMenu = mainMenuPage->Selector();
			mainMenuPage->Erase();
		}

		if (currentMenu == "startCalc")
		{
			startCalcPage->Print();
			//currentMenu = startCalcPage->Selector();

			startCalcPage->Selector();
			startCalcPage->Erase();
			currentMenu = "mainMenuPage";







		}

		if (currentMenu == "optionPage")
		{
			Layout* optionPage = layoutFactory.optionPage();

			optionPage->Print();
			currentMenu = optionPage->Selector();
			optionPage->Erase();

			delete optionPage;
		}

		if (currentMenu == "exitPage")
		{
			Layout* exitPage = layoutFactory.exitPage();

			exitPage->Print();
			Sleep(1000);
			
			delete exitPage;
			break;
		}
	}

	return 0;
}
