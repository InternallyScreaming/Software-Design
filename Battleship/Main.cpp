#pragma once
#include "ShipSub.h"
#include <Windows.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

//different game states
enum GameStates {
	GAME = 1,
	CREDITS,
	EXIT
};

//function to reduce redundancy in the code as both player's will be inputing their attack coordinates
//the system will check for valid inputs and input combinations that were not previously checked.
void playerInput(Player * attacker, Player * defender, Render renderer, Physics physic);

//changes a char value of a-j(capital or lowercase) into a 0-9 value
int charToInt(char letter);

void main() {
	Render render;
	Physics calculate;
	int menuOption;
	bool menuRunning = true; //for gamestate loop
	bool gameRunning = true; //for game loop

	//loop through all game states
	//will exit when the player enters in a value of 3
	while (menuRunning) {
		
		//draw menu
		render.DrawMenu();

		//requesting a valid input
		do {
			cin >> menuOption;
		} while (menuOption != 1 && menuOption != 2 && menuOption != 3);

		//////////////////////////////////////////GAME//////////////////////////////////////////
		if (menuOption == GAME) {
			//BEFORE THE GAME STARTS

			//seed randomizer and clear screen
			srand(time(NULL));
			system("CLS");
			
			//creates Player 1 and draws their board
			Player Player1("Player 1");
			//render.DrawFleet(Player1.m_fleet, 51, 4); //for debugging
			render.DrawBoard(Player1.GetName(), Player1.m_playerBoard, 50, 2, Player1.m_enemyAttacks);
			render.DrawDivide();

			//creates Player 2 and draws their board
			Player Player2("Player 2");
			//render.DrawFleet(Player2.m_fleet, 51, 18); //for debugging
			render.DrawBoard(Player2.GetName(), Player2.m_playerBoard, 50, 16, Player2.m_enemyAttacks);
			
			//GAMEPLAY
			while (gameRunning) {
				/////////////////////////////////////Player 1 attacking/////////////////////////////////////
				playerInput(&Player1, &Player2, render, calculate);
				render.DrawBoard(Player2.GetName(), Player2.m_playerBoard, 50, 16, Player2.m_enemyAttacks);
				////////////////////////////////////////////////////////////////////////////////////////////

				//Will declare when a single boat is sunk
				if (calculate.confirmBoatSink(*Player2.AircraftCarrier)) {
					render.SinkMessage(Player2, 1, 5, 18);
				}
				if (calculate.confirmBoatSink(*Player2.BattleShip)) {
					render.SinkMessage(Player2, 2, 5, 19);
				}
				if (calculate.confirmBoatSink(*Player2.Sub)) {
					render.SinkMessage(Player2, 3, 5, 20);
				}
				if (calculate.confirmBoatSink(*Player2.Cruise)) {
					render.SinkMessage(Player2, 4, 5, 21);
				}
				if (calculate.confirmBoatSink(*Player2.Destroy)) {
					render.SinkMessage(Player2, 5, 5, 22); 
				}
				
				//will be declared when allof player2's boats have sunk
				//player 1 will win
				//destroy instances of both players
				//end the game loop
				if (calculate.confirmAllSink(Player2.m_fleet)) {
					render.gotoXY(0, 0);
					cout << "Player 1 wins the game!\n";
					system("pause");

					Player1.~Player();
					Player2.~Player();
					gameRunning = false;
				}
				
				//Player 2 will attack if their boats are not all sunk
				else {
					/////////////////////////////////////Player 2 attacking/////////////////////////////////////
					playerInput(&Player2, &Player1, render, calculate);
					render.DrawBoard(Player1.GetName(), Player1.m_playerBoard, 50, 2, Player1.m_enemyAttacks);
					////////////////////////////////////////////////////////////////////////////////////////////
				}

				//Will declare when a single boat is sunk
				if (calculate.confirmBoatSink(*Player1.AircraftCarrier)) {
					render.SinkMessage(Player1, 1, 75, 0);
				}
				if (calculate.confirmBoatSink(*Player1.BattleShip)) {
					render.SinkMessage(Player1, 2, 75, 1);
				}
				if (calculate.confirmBoatSink(*Player1.Sub)) {
					render.SinkMessage(Player1, 3, 75, 2);
				}
				if (calculate.confirmBoatSink(*Player1.Cruise)) {
					render.SinkMessage(Player1, 4, 75, 3);
				}
				if (calculate.confirmBoatSink(*Player1.Destroy)) {
					render.SinkMessage(Player1, 5, 75, 4);
				}
				
				//will be declared when allof player2's boats have sunk
				//player 2 will win
				//destroy instances of both players
				//end the game loop
				if (calculate.confirmAllSink(Player1.m_fleet)) {
					render.gotoXY(0, 0);
					cout << "Player 2 wins the game!\n";
					system("pause");

					Player1.~Player();
					Player2.~Player();
					gameRunning = false;
				}
			}
		}
		//////////////////////////////////////////CREDITS//////////////////////////////////////////
		else if (menuOption == CREDITS) {
			render.DrawCredits();
		}
		//////////////////////////////////////////EXIT//////////////////////////////////////////
		else if (menuOption == EXIT) {
			render.DrawGoodbye();
			menuRunning = false;
		}
	}
}

void playerInput(Player * attacker, Player * defender, Render renderer, Physics physic) {
	int X;
	char Y;
	int intY;
	Vec2 playerChoice;

	//attacking player is prompted to input coordinates
	renderer.DrawTurnPrompt(attacker->GetName());

	do { //continue until the player gives an attacking coordinate that they have not used yet
		//In battleship, it is natural for the player to say the Y coordinate then the X coordinate
		//for example A9

		//Enter Y coordinate first
		renderer.gotoXY(75, 21);
		cout << "Y:";
		renderer.gotoXY(79, 21);

		do { //continue to ask player for a valid Y answer
			renderer.gotoXY(79, 21);
			cin >> Y;
		} while (physic.checkY(Y));

		//Enter X cootdinate next
		renderer.gotoXY(75, 22);
		cout << "X:";
		renderer.gotoXY(79, 22);

		do { //continue to ask player for a valid X answer
			renderer.gotoXY(79, 22);
			cin >> X;
		} while (physic.checkX(X));

		//"converts" char value into an int
		//example, an A will be return as a 0, and a J will return as a 9
		//This is for easier calculations as the y-axis will match the x axis
		//player's will not know of this if they only play the game
		intY = charToInt(Y);
		playerChoice.m_X = X;
		playerChoice.m_Y = intY;

		if (attacker->checkChoices(*attacker, playerChoice)) {
			renderer.gotoXY(75, 24);
			cout << attacker->GetName() << ", you already made that choice";
			renderer.gotoXY(75, 25);
			system("pause");
			renderer.ClearScreenSection();
		}

	} while (attacker->checkChoices(*attacker, playerChoice));

	//push back attack coordinates into playerchoice vector
	//therefore those coordinates can no longer be chosen
	attacker->m_playerChoices.push_back(playerChoice);

	//check the player hit the opponent's boat
	//if yes
	if (physic.attackToAllCollision(defender->m_fleet, X, intY)) {
		//say that they hit the boat
		//register hit to the defender's enemyattacks array
		renderer.gotoXY(79, 23);
		cout << "hit" << endl;
		defender->m_enemyAttacks[intY][X] = 3;
		Sleep(500);
	}
	//if not
	else {
		//say that they hit the boat
		//register the miss to the defender's enemyattacks array
		renderer.gotoXY(79, 23);
		cout << "miss" << endl;
		defender->m_enemyAttacks[intY][X] = 2;
		Sleep(500);
	}

}
//"converts" char value into an int
//example, an A will be return as a 0, and a J will return as a 9
//This is for easier calculations as the y-axis will match the x axis
//player's will not know of this if they only play the game
int charToInt(char letter) {
	if (letter == (char)65 || letter == (char)97){
		return 0;
	}
	else if (letter == (char)66 || letter == (char)98) {
		return 1;
	}
	else if (letter == (char)67 || letter == (char)99) {
		return 2;
	}
	else if (letter == (char)68 || letter == (char)100) {
		return 3;
	}
	else if (letter == (char)69 || letter == (char)101) {
		return 4;
	}
	else if (letter == (char)70 || letter == (char)102) {
		return 5;
	}
	else if (letter == (char)71 || letter == (char)103) {
		return 6;
	}
	else if (letter == (char)72 || letter == (char)104) {
		return 7;
	}
	else if (letter == (char)73 || letter == (char)105) {
		return 8;
	}
	else if (letter == (char)74 || letter == (char)106) {
		return 9;
	}
}