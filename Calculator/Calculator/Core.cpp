#include "Core.h"


void Core::Run()
{
	LayoutFactory layoutFactory;
	Layout* mainFrame = layoutFactory.mainFrame(0, 0);
	Layout* introPage = layoutFactory.introPage(0, 0);
	Layout* mainMenuPage = layoutFactory.mainMenuPage(2, 47);
	Layout* startCalcPage = layoutFactory.startCalcPage(4, 4);
	Layout* optionPage = layoutFactory.optionPage();
	Layout* exitAskPage = layoutFactory.exitAskPage();
	Layout* exitPage = layoutFactory.exitPage();
	string nextMenu = "mainMenuPage";
	string currentMenu = "mainMenuPage";
	string prevMenu = "mainMenuPage";

	Sleep(1000);
	introPage->Print();
	Sleep(3000);
	introPage->Erase();
	Sleep(1000);

	mainFrame->Print();

	for (;;)
	{
		prevMenu = currentMenu;
		currentMenu = nextMenu;

		//////////////
		//*  Menu  *//
		//////////////
		if (nextMenu == "mainMenuPage")
		{
			mainMenuPage->Print();
			nextMenu = mainMenuPage->Selector();
			mainMenuPage->Erase();
		}

		else if (nextMenu == "startCalc")
		{
			startCalcPage->Print();
			nextMenu = startCalcPage->Selector();
			startCalcPage->Erase();
			nextMenu = "mainMenuPage"; // TEMP
		}

		else if (nextMenu == "optionPage")
		{
			optionPage->Print();
			nextMenu = optionPage->Selector();
			optionPage->Erase();
		}





		///////////////////
		//*  ESC Check  *//
		///////////////////

		if (nextMenu == "ESC" || nextMenu == "exitAskPage")
		{
			if (currentMenu == "mainMenuPage")
			{
				exitAskPage->Print();

				if (exitAskPage->Selector() == "yes")
				{
					exitAskPage->Erase();
					exitPage->Print();
					Sleep(1000);

					delete exitPage;
					break;
				}
				else
					nextMenu = currentMenu;

				exitAskPage->Erase();
			}
			else
				nextMenu = prevMenu;
		}
	}
}


