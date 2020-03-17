#pragma once
#include "ShipSub.h"
#include <conio.h>

//define the numeric digit for the colour white
#define WHITE 15

enum boat {
	AIRCRAFTCARRIER = 1,
	BATTLESHIP,
	SUB,
	CRUISER,
	DESTROYER
};

Render::~Render(){}	//constuctor
Render::Render() {}	//destructor

//clears the screen, print the menu
void Render::DrawMenu(){
	system("CLS");
	gotoXY(30, 0);
	cout << "||     *                            *                    ((   *  ||";
	gotoXY(30, 1);
	cout << "||        *                 *                *            ~      ||";
	gotoXY(30, 2);
	cout << "||                ___.                          *          *     ||";
	gotoXY(30, 3);
	cout << "||       *    ___.\\__|.__.           *                           ||";
	gotoXY(30, 4);
	cout << "||            \\__|. .| \\_|.                                      ||";
	gotoXY(30, 5);
	cout << "||            . X|___|___| .                         *           ||";
	gotoXY(30, 6);
	cout << "||          .__/_||____ ||__.            *                /\\     ||";
	gotoXY(30, 7);
	cout << "||  *     .  |/|____ |_\\|_ |/ _                          /  \\    ||";
	gotoXY(30, 8);
	cout << "||        \\ _/ |_X__\\|_  |\\||~,~{                       /    \\   ||";
	gotoXY(30, 9);
	cout << "||         \\/\\ |/|    |_ |/:|`X'{                   _ _/      \\__||";
	gotoXY(30, 10);
	cout << "||          \\ \\/ |___ |_\\|_.|~~~                   /    . .. . ..||";
	gotoXY(30, 11);
	cout << "||         _|X/\\ |___\\|_ :| |_.                  - .......... . .||";
	gotoXY(30, 12);
	cout << "||         | __\\_:____ |  ||o-|            ___/........ . . .. ..||";
	gotoXY(30, 13);
	cout << "||         |/_-|-_|__ \\|_ |/--|       ____/  . . .. . . .. ... . ||";
	gotoXY(30, 14);
	cout << "|| ........:| -|- o-o\\_:_\\|o-/:....../...........................||";
	gotoXY(30, 15);
	cout << "|| ._._._._._\\=\\====o==o==o=/:.._._._._._._._._._._._._._._._._._||";
	gotoXY(30, 16);
	cout << "|| _._._._._._\\_\\ ._._._._.:._._._._._._._._._._._._._.P_._._._._||";
	gotoXY(30, 17);
	cout << "|| ._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._||";
	gotoXY(30, 18);
	cout << "||---------------------------------------------------------------||";
	gotoXY(30, 19);
	cout << "||                   WELCOME TO BATTLESHIP!                      ||";
	gotoXY(30, 20);
	cout << "||---------------------------------------------------------------||";
	gotoXY(30, 21);
	cout << "||                   1-PLAY GAME                                 ||";
	gotoXY(30, 22);
	cout << "||                   2-CREDITS                                   ||";
	gotoXY(30, 23);
	cout << "||                   3-EXIT                                      ||";
	gotoXY(30, 24);
	cout << "||---------------------------------------------------------------||";
	gotoXY(30, 25);
}

//clears the screen, print the credits, pauses the program
void Render::DrawCredits(){
	system("CLS");
	gotoXY(30, 0);
	cout << "||---------------------------------------------------------------||";
	gotoXY(30, 1);
	cout << "||                          CREDITS                              ||";
	gotoXY(30, 2);
	cout << "||---------------------------------------------------------------||";
	gotoXY(30, 3);
	cout << "||CREATED BY........................................AMANDA MCLEOD||";
	gotoXY(30, 4);
	cout << "||................................................& TIFFANY WIEBE||";
	gotoXY(30, 5);
	cout << "||---------------------------------------------------------------||";
	gotoXY(30, 6);
	system("pause");
}

//prints the goodbye text, pauses the program
void Render::DrawGoodbye() {
	cout << "Good Bye! \n";
	system("pause");
}
//draws a single ship at its position
//called only by DrawFleet
//USED ONLY FOR DEBUGGING PURPOSES
void Render::DrawShip(Ship * Ship, int offsetX, int offsetY){
	for (int i = 0; i < Ship->GetSize(); i++) {
		gotoXY(Ship->m_boatPos[i].m_X + offsetX, Ship->m_boatPos[i].m_Y + offsetY);
		cout << (char)219;
	}
}

//draws a whole fleet of ships at their positions
//calls DrawShip
//USED ONLY FOR DEBUGGING PURPOSES
void Render::DrawFleet(vector<Ship*>& fleet, int offsetX, int offsetY) {
	SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_RED);
	for (unsigned int i = 0; i < fleet.size(); i++) {
		DrawShip(fleet[i], offsetX, offsetY);
	}
}

//draws the player's board
void Render::DrawBoard(string player, char playArea[10][10], int offsetX, int offsetY, int hits[10][10]) {
	//set text color to green
	SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_GREEN);
	int letter = 65;

	//print player's name above their board
	gotoXY(offsetX, offsetY);
	cout << player << ": \n";
	offsetY++;
	
	//draws the X-axis coordinates
	gotoXY(offsetX, offsetY);
	cout << " 0123456789" << endl;
	offsetY++;

	//draw the battle area of the board and the Y-axis coordinats
	for (unsigned int i = 0; i < 10; i++) {
		//draws the Y-axis coordinates by calling their ascii code
		SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_GREEN);
		gotoXY(offsetX, offsetY);
		cout << (char)letter;

		//draws the battle area
		for (int j = 0; j < 10; j++) {
			//default blue board
			if (hits[i][j] == 1) {
				SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_BLUE);
				playArea[i][j] = (char)219;
				cout << playArea[i][j];
			}
			//if enemy misses
			if (hits[i][j] == 2) {
				SetConsoleTextAttribute(ConsoleHandle, WHITE);
				playArea[i][j] = (char)88;
				cout << playArea[i][j];
			}
			//if enemy hits
			if (hits[i][j] == 3) {
				SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_RED);
				playArea[i][j] = (char)219;
				cout << playArea[i][j];
			}
		}
		cout << "\n";
		letter++;
		offsetY++;
	}
}

//sets text colour to white and draws the dotted white line in the middle of the screen
void Render::DrawDivide() {
	SetConsoleTextAttribute(ConsoleHandle, WHITE);
	cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
}

//sets text colour to white
//prints prompt for user to input coordinates
void Render::DrawTurnPrompt(string player) {
	SetConsoleTextAttribute(ConsoleHandle, WHITE);
	gotoXY(75, 19);
	cout << player <<"'s turn";

	ClearScreenSection();
	gotoXY(75, 20);
	cout << "Enter in the Coordinates:";
}

//clears certain parts of the screen
void Render::ClearScreenSection(){
	int Y = 21;
	for (unsigned int i = 0; i < 6; i++) {
		gotoXY(75, Y);
		for (unsigned int j = 0; j < 40; j++) {
			cout << (char)255;
		}
		Y++;
	}
	Y = 20;
	for (unsigned int i = 0; i < 4; i++) {
		gotoXY(0, Y);
		for (unsigned int j = 0; j < 4; j++) {
			cout << (char)255;
		}
		Y++;
	}
}

//prints the sink message of the boats
void Render::SinkMessage(Player player, int boat, int offsetX, int offsetY){
	//goes to coordinates
	//sets text colour to white
	//specify whose boat sunk
	gotoXY(offsetX, offsetY);
	SetConsoleTextAttribute(ConsoleHandle, WHITE);
	cout << player.GetName() << "'s ";

	//print specific boat's sink message
	switch (boat) {
	case AIRCRAFTCARRIER:
		player.AircraftCarrier->sinkMessage();
		break;
	case BATTLESHIP:
		player.BattleShip->sinkMessage();
		break;
	case SUB:
		player.Sub->sinkMessage();
		break;
	case CRUISER:
		player.Cruise->sinkMessage();
		break;
	case DESTROYER:
		player.Destroy->sinkMessage();
		break;
	}
}

//moves the cursor to different coordinates
void Render::gotoXY(int x, int y) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {x, y};
	SetConsoleCursorPosition(hStdout, position);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = false;
	cursorInfo.dwSize = 10;
	SetConsoleCursorInfo(hStdout, &cursorInfo);
}
