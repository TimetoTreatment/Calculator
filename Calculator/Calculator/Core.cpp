#include "Core.h"
#define DEBUG 1


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
	Layout* basicCalcPage = layoutFactory.basicCalcPage();
	string nextMenu = "mainMenuPage";
	string currentMenu = "mainMenuPage";
	string prevMenu = "mainMenuPage";

#if !DEBUG
	Sleep(1000);
	introPage->Print();
	Sleep(3000);
	introPage->Erase();
	Sleep(1000);
#endif

	mainFrame->Print();

	for (;;)
	{
		prevMenu = currentMenu;
		currentMenu = nextMenu;

		//////////////
		//*  Menu  *//
		//////////////

		// Phase 1
		if (nextMenu == "mainMenuPage")
		{
			mainMenuPage->Print();
			nextMenu = mainMenuPage->Select();
			mainMenuPage->Erase();
		}

		// Phase 2
		else if (nextMenu == "startCalcPage")
		{
			startCalcPage->Print();
			nextMenu = startCalcPage->Select();
			startCalcPage->Erase();
		}

		else if (nextMenu == "optionPage")
		{
			optionPage->Print();
			nextMenu = optionPage->Select();
			optionPage->Erase();
		}

		// Phase 3
		else if (nextMenu == "basicCalcPage")
		{
			basicCalcPage->Print();

			nextMenu = basicCalcPage->Select();

			basicCalcPage->Erase();
		}


		////////////////////
		//*  Exit Check  *//
		////////////////////

		if (nextMenu == "exitAskPage")
		{

			exitAskPage->Print();

			if ((nextMenu = exitAskPage->Select()) == "exitPage")
			{
				exitAskPage->Erase();
				exitPage->Print();
				Sleep(1000);

				delete exitPage;
				break;	// Loop END
			}

			exitAskPage->Erase();
		}

	}
}


