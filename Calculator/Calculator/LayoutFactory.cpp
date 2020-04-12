#include "LayoutFactory.h"


Layout* LayoutFactory::simpleCalc(Layout* frame)
{
	Layout* simpleCalc = new Layout;

	frame->AddPart(simpleCalc);
	simpleCalc->SetName("simpleCalc");
	simpleCalc->SetColor("white");
	simpleCalc->PushString(" _____________________");
	simpleCalc->PushString("|  _________________  |");
	simpleCalc->PushString("| |                 | |");
	simpleCalc->PushString("| |                 | |");
	simpleCalc->PushString("| |_________________| |");
	simpleCalc->PushString("|  __ __ __ __ __ __  |");
	simpleCalc->PushString("| |__|__|__|__|__|__| |");
	simpleCalc->PushString("| |__|__|__|__|__|__| |");
	simpleCalc->PushString("|  ___ ___ ___   ___  |");
	simpleCalc->PushString("| | 7 | 8 | 9 | | + | |");
	simpleCalc->PushString("| |___|___|___| |___| |");
	simpleCalc->PushString("| | 4 | 5 | 6 | | - | |");
	simpleCalc->PushString("| |___|___|___| |___| |");
	simpleCalc->PushString("| | 1 | 2 | 3 | | x | |");
	simpleCalc->PushString("| |___|___|___| |___| |");
	simpleCalc->PushString("| | . | 0 | = | | / | |");
	simpleCalc->PushString("| |___|___|___| |___| |");
	simpleCalc->PushString("|_____________________|");

	return simpleCalc;
}


Layout* LayoutFactory::mainFrame(int startRow, int startCol)
{
	Layout* mainFrame = new Layout;
	string frameTop;
	string frameSide;
	string frameBottom;

	mainFrame->SetName("mainFrame");
	mainFrame->SetCoord(startRow, startCol);
	mainFrame->SetColor("white");

	frameTop.resize(120, '#');
	frameSide.resize(120, ' ');
	frameSide[0] = '#';
	frameSide[1] = '#';
	frameSide[118] = '#';
	frameSide[119] = '#';
	frameBottom.resize(120, '#');
	////////////////////////
	//     * DEBUG *      //
	frameTop[59] = 'C';   //
	frameTop[60] = 'C';   //
	frameBottom[59] = 'C';//
	frameBottom[60] = 'C';//
	//     * DEBUG *      //
	////////////////////////

	mainFrame->PushString(frameTop);

	for (int row = 1; row <= 28; row++)
		mainFrame->PushString(frameSide);

	mainFrame->PushString(frameBottom);

	return mainFrame;
}


Layout* LayoutFactory::introPage(int startRow, int startCol)
{
	Layout* introPage = new Layout;
	Layout* team = new Layout(introPage);
	Layout* member = new Layout(introPage);
	Layout* project = new Layout(introPage);

	introPage->SetCoord(3, 3);
	introPage->SetSize(25, 110);
	
	team->SetName("team");
	team->SetColor("white");
	team->SetRelativeCoord(1, 25);
	team->PushString(" /$$$$$$$$                                        /$$");
	team->PushString("|__  $$__/                                      /$$$$");
	team->PushString("   | $$  /$$$$$$   /$$$$$$  /$$$$$$/$$$$       |_  $$");
	team->PushString("   | $$ /$$__  $$ |____  $$| $$   $$   $$        | $$");
	team->PushString("   | $$| $$$$$$$$  /$$$$$$$| $$‖ $$‖ $$        | $$");
	team->PushString("   | $$| $$_____/ /$$__  $$| $$ | $$ | $$        | $$");
	team->PushString("   | $$|  $$$$$$$|  $$$$$$$| $$ | $$ | $$       /$$$$$$");
	team->PushString("   |__/ ‖______/ ‖______/|__/ |__/ |__/      |______/");

	member->SetName("member");
	member->SetRelativeCoord(1, 39);
	member->SetColor("white");
	member->PushString("辣扒龋  巨公货  逛公货  内春绢");

	project->SetName("project");
	project->SetColor("green");
	project->SetRelativeCoord(14, 4);
	project->PushString(":'######:::::'###::::'##::::::::'######::'##::::'##:'##::::::::::'###::::'########::'#######::'########::");
	project->PushString("'##... ##:::'## ##::: ##:::::::'##... ##: ##:::: ##: ##:::::::::'## ##:::... ##..::'##.... ##: ##.... ##:");
	project->PushString(" ##:::..:::'##:. ##:: ##::::::: ##:::..:: ##:::: ##: ##::::::::'##:. ##::::: ##:::: ##:::: ##: ##:::: ##:");
	project->PushString(" ##:::::::'##:::. ##: ##::::::: ##::::::: ##:::: ##: ##:::::::'##:::. ##:::: ##:::: ##:::: ##: ########::");
	project->PushString(" ##::::::: #########: ##::::::: ##::::::: ##:::: ##: ##::::::: #########:::: ##:::: ##:::: ##: ##.. ##:::");
	project->PushString(" ##::: ##: ##.... ##: ##::::::: ##::: ##: ##:::: ##: ##::::::: ##.... ##:::: ##:::: ##:::: ##: ##::. ##::");
	project->PushString(". ######:: ##:::: ##: ########:. ######::. #######:: ########: ##:::: ##:::: ##::::. #######:: ##:::. ##:");
	project->PushString(":......:::..:::::..::........:::......::::.......:::........::..:::::..:::::..::::::.......:::..:::::..::");

	return introPage;
}



Layout* LayoutFactory::mainMenuPage(int startRow, int startCol)
{
	Layout* mainMenuPage = new Layout;
	Layout* introCalc = this->simpleCalc(mainMenuPage);
	Layout* title = new Layout(mainMenuPage);
	Menu* startCalc = new Menu(mainMenuPage);
	Menu* option = new Menu(mainMenuPage);
	Menu* exit = new Menu(mainMenuPage);

	mainMenuPage->SetName("mainMenuPage");
	mainMenuPage->SetCoord(startRow, startCol);
	mainMenuPage->SetSize(25, 30);

	introCalc->SetName("introCalc");
	introCalc->SetRelativeCoord(0, 1);

	title->SetName("title");
	title->SetRelativeCoord(3, 9);
	title->PushString("MainMenu", "white");

	startCalc->PushString("Start Calculator", "red");
	startCalc->SetName("startCalc");
	startCalc->SetRelativeCoord(20, 5);
	startCalc->SetFirstPart();

	option->PushString("Option", "green");
	option->SetName("optionPage");
	option->SetRelativeCoord(22, 10);

	exit->PushString("Exit", "blue");
	exit->SetName("exitAskPage");
	exit->SetRelativeCoord(24, 11);

	return mainMenuPage;
}

Layout* LayoutFactory::optionPage()
{
	Layout* optionPage = new Layout;
	Layout* title = new Layout(optionPage);
	Layout* temp = new Layout(optionPage);
	Menu* back = new Menu(optionPage);

	optionPage->SetName("optionPage");
	optionPage->SetCoord(5, 48);
	optionPage->SetSize(20, 30);

	title->SetRelativeCoord(0, 7);
	title->PushString("* Option *", "green");

	temp->SetRelativeCoord(3, 4);
	temp->PushString("To be construct...", "yellow");

	back->SetRelativeCoord(9, 1);
	back->SetName("mainMenuPage");
	back->PushString("Press ENTER to continue", "white");

	return optionPage;
}

Layout* LayoutFactory::exitAskPage()
{
	Layout* exitAskPage = new Layout;
	Layout* title = new Layout(exitAskPage);
	Layout* body = new Layout(exitAskPage);
	Menu* yes = new Menu(exitAskPage);
	Menu* no = new Menu(exitAskPage);

	exitAskPage->SetName("exitAskPage");
	exitAskPage->SetCoord(7, 49);
	exitAskPage->SetSize(20, 25);

	title->SetRelativeCoord(0, 7);
	title->PushString("* Exit *", "blue");

	body->SetRelativeCoord(5, 4);
	body->PushString("Are you sure ?", "white");

	yes->SetRelativeCoord(9, 0);
	yes->SetName("yes");
	yes->PushString("[ Yes ]", "white");

	no->SetRelativeCoord(9, 16);
	no->SetName("no");
	no->PushString("[ No ]", "white");

	return exitAskPage;
}


Layout* LayoutFactory::exitPage()
{
	Layout* exitPage = new Layout;
	Layout* title = new Layout(exitPage);
	Layout* body = new Layout(exitPage);

	exitPage->SetName("exitPage");
	exitPage->SetCoord(7, 51);
	exitPage->SetSize(20, 20);

	title->SetRelativeCoord(0, 5);
	title->PushString("* Exit *", "blue");

	body->SetRelativeCoord(4, 1);
	body->PushString("Exiting Program...", "white");

	return exitPage;
}


Layout* LayoutFactory::startCalcPage(int startRow, int startCol)
{
	Layout* startCalcPage = new Layout;
	Layout* basicCalcSpec = new Layout(startCalcPage);
	Layout* basicCalcLayout = new Layout(startCalcPage);
	Menu* basicCalcMenu = new Menu(startCalcPage);
	Layout* advencedCalcSpec = new Layout(startCalcPage);
	Layout* advencedCalcLayout = this->simpleCalc(startCalcPage);
	Menu* advencedCalcMenu = new Menu(startCalcPage);

	startCalcPage->SetName("startCalcPage");
	startCalcPage->SetCoord(2, 10);
	startCalcPage->SetSize(25, 100);




	//basicCalcTitle->PushString("< Basic Calculator >", "white");
	//basicCalcTitle->SetRelativeCoord(0, 17);

	basicCalcLayout->SetName("basicCalcLayout");
	basicCalcLayout->SetRelativeCoord(3, 0);
	basicCalcLayout->SetColor("white");
	basicCalcLayout->PushString(" _____________________ ");
	basicCalcLayout->PushString("|  _________________  |");
	basicCalcLayout->PushString("| |                 | |");
	basicCalcLayout->PushString("| |                 | |");
	basicCalcLayout->PushString("| |_________________| |");
	basicCalcLayout->PushString("|  __ __ __ __ __ __  |");
	basicCalcLayout->PushString("| |__|__|__|__|__|__| |");
	basicCalcLayout->PushString("| |__|__|__|__|__|__| |");
	basicCalcLayout->PushString("|  ___ ___ ___   ___  |");
	basicCalcLayout->PushString("| | 7 | 8 | 9 | | + | |");
	basicCalcLayout->PushString("| |___|___|___| |___| |");
	basicCalcLayout->PushString("| | 4 | 5 | 6 | | - | |");
	basicCalcLayout->PushString("| |___|___|___| |___| |");
	basicCalcLayout->PushString("| | 1 | 2 | 3 | | x | |");
	basicCalcLayout->PushString("| |___|___|___| |___| |");
	basicCalcLayout->PushString("| | . | 0 | = | | / | |");
	basicCalcLayout->PushString("| |___|___|___| |___| |");
	basicCalcLayout->PushString("|_____________________|");
	basicCalcLayout->PushString("");

	basicCalcSpec->SetRelativeCoord(5, 25);
	basicCalcSpec->SetColor("white");
	basicCalcSpec->PushString("  < Basic Calculator >");
	basicCalcSpec->PushString("");
	basicCalcSpec->PushString("");
	basicCalcSpec->PushString("* For basic operations.");
	basicCalcSpec->PushString("");
	basicCalcSpec->PushString("* Four operations support.");


	basicCalcMenu->SetName("basicCalcSelect");
	basicCalcMenu->SetRelativeCoord(6, 9);
	basicCalcMenu->PushString("BASIC", "blue");
	basicCalcMenu->SetFirstPart();

	advencedCalcLayout->SetName("advencedCalcLayout");
	advencedCalcLayout->SetRelativeCoord(3, 73);

	advencedCalcSpec->SetRelativeCoord(15, 45);
	advencedCalcSpec->SetColor("white");
	advencedCalcSpec->PushString("  < Advenced Calculator >");
	advencedCalcSpec->PushString("");
	advencedCalcSpec->PushString("");
	advencedCalcSpec->PushString("* For advenced operations.");
	advencedCalcSpec->PushString("");
	advencedCalcSpec->PushString("* TouchScreen support.");

	advencedCalcMenu->SetName("advencedCalcSelect");
	advencedCalcMenu->SetRelativeCoord(6, 81);
	advencedCalcMenu->PushString("ADVENCE", "red");



	return startCalcPage;
}