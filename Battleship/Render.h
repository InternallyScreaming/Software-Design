#pragma once
#include "Ship.h"
#include "Player.h"
#include <Windows.h>

//Draws most graphics to the screen
class Render{
protected:
	//used to change the color of the text
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	~Render();		//constuctor
	Render();		//destructor

	void DrawMenu();		//draws the menu
	void DrawCredits();		//draws the credits
	void DrawGoodbye();		//draws the goodby text
	//draws a single ship, called only by DrawFleet, used only for debugging purposes
	void DrawShip(Ship * Ship, int offsetX, int offsetY);
	//calls DrawShip to draw all the ships in the player's fleet, used only for debugging purposes
	void DrawFleet(vector<Ship*>& fleet, int offsetX, int offsetY);
	//draws the player's board
	void DrawBoard(string player, char playArea[10][10], int offsetX, int offsetY, int hits[10][10]);
	//draws the dotted line between the two player boards
	void DrawDivide();
	//draws the turn prompt for each player
	void DrawTurnPrompt(string player);
	//clears only certain parts of the screen
	void ClearScreenSection();
	//prints the sink message of the boats
	void SinkMessage(Player player, int boat, int offsetX, int offsetY);
	//moves the cursor to different coordinates
	void gotoXY(int x, int y);
};

