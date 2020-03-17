//Title:		Assignment-1
//Author:		Tiffany Wiebe
//Objective:	To create a text based game with no graphical or mutimedia content.
//				This will be created in C++.
//Design Desc:	This code is a dice game where the player can select a number of dice to be rolled,
//				and afterwards be prompted to guess if the next roll will be higher, lower or a tie.
//				
//				The game starts off with the menu function being printed to the screen, the menu is in a separate
//				function for easier loading and readabliy of the code.  The menu function also has a clear screen
//				function so that the screen is cleared every time the menu opens.  The user is asked to make a prompt
//				and the code will either load up the user's choice or ask for a valid prompt.  Also in the main function
//				is where the randomizer is seeded for the dice
//				
//				Side Note: An enum of Game States is created of all different game states: GAME, CREDITS, and EXIT.
//				This is for easier readability in the switch/case statement that handles the code's different states.
//				
//				Down below is a break down of the functionality of all the different game states.
//				
//				GAME: If the user enters in the game option the game function is called.  The console screen is cleared
//				and two vectors are created, one for the first set of rolled dice, the other for the second set.  Vectors
//				were used instead of arrays as they inherently dynamic by nature and have built-in functions that are
//				significantly useful.  The reason that I need vectors is that I do not know how many dice a person would want to roll.
//				I could limit the number of dice rolled but that is no fun.
//				
//				Continuing with the code, the user is prompted to input the number of dice that they want to roll.  After entering the 
//				number of desired dice, the rollDie function is called which will be explained down below.
//				
//					ROLL DIE FUNCTION:	The roll die function takes in the arguements of the number of dice that the user inputed
//					at the start of the game, a reference of one of the vectors that was created, and a value of offset Y.
//					
//					Side Note: The number of dice value will control the for loop that is in the function so that the desired number of 
//					dice is created.
//					
//					The reason why I am passing in a reference rather than a value is that #1 this is a void function, so nothing is returned.
//					I could make it a vector function and initialize the value of my vectors made in the game function to the return value of the function.
//					The down side of this being that this function prints stuff to the console, so by initializing the vectors to the return value of the function
//					would result in objects being printed to the screen.  It is far easier to have these vectors be passed in by reference as I 
//					only need the values of the individual dice rolls and this function is supposed to print to the consol.
//					
//					Lastly, there is offsetY.  I went back to an old assignment for Intermediate Programming where my professor Chris Ziraldo gave
//					us the gotoXY function.  This function takes in an x and y value and it will move the cursor to another part of the console
//					window.  This is very useful when drawing in ASCII art.  This offset Y value will allow for me to display both sets of dice
//					that were rolled.
//					
//					Continuing the Roll Die function, an offsetX value is created and initialized to 0.  The for loop will iterate to the amount of dice
//					that the player entered in before. A number from 1 - 6 is randomized, this value gets pushed into the vector.  A switch/case 
//					statement follows, each case corresponds the 6 faces on a die.  In each case two functions are called, the first one 
//					is the function to draw the little dots for that die's face, the second is draw the outer border of the dice.  The functions were
//					split up like this because all the faces on the die will have the same border.  And some of the dots on the die share similar 
//					patters. For example, the 3 face function, calls up the 1 face and 2 face function to compose it.  The 4 face calls up
//					the 2 face and then adds the two extra dots.  The 5 face is composed of the 1 face and 4 face function and the six face
//					calls the 4 face and adds the 2 extra dots it needs to make 6.
//					
//					After the end of the for loop, the offsetX adds 10 to itself so that all the dice are drawn side by side instead of right
//					on top of one another.  The first time the rollDie function is called the offsetY value is not really important as it will be 0
//					for the first set of dice.  But for the next set it will allow for the new set to be drawn bellow the first set.
//						
//				After the roll die function is done its first set, the total function is called which has the first dice set vector passed into it
//				and it will return the sum of all the indexes in that vector.  Te user will then be asked if the next roll will be higher, 
//				lower, or a tie.  The user inputs their guess. Then the roll die function is called only this time, the second vector is 
//				passed in and the offset Y will be 5 instead of 0.
//				
//				After the second roll, a total of the first roll will be printed followed by the second roll.  Next the print results function
//				will be called, with the results function being passed in as a value.
//				
//					RESULTS FUNCTION:	The results function takes in the return values of the first dice roll, second dice roll, and the
//					choice that player made whether the second roll was higher, lower, or a tie.  This function then calls up tiny boolean
//					functions to compare whether or not the first set was higher, the second set was higher, or if it was a tie.  The higher
//					boolean function will return true if the second total was bigger, the lower will return true if the second total was 
//					smaller, and tie will return true if both the first and second totals are the same.  After checking between the two totals,
//					this function will then check if the player guessed correctly.  Example, if the second number was higher than the first, and 
//					the player guessed correctly.  If the player guessed correctly, this function will return true, if not the function will return false.
//				
//					PRINT RESULTS FUNCTION: this function takes in the the boolean return of the results function.  It will then print the proper response.
//				
//				After the results are printed the system pauses and the player needs to press any key to continue.  The game function is now complete
//				and the player is returned to the menu.
//				
//				CREDITS: credits is just like the menu.  The console window clears and the credits are printed to the screen the function ends and
//				in the main function's switch case statement, another system pause is called so that the player can read the text and press
//				any key to continue.
//				
//				EXIT: when chosen a good bye message is displayed and system pause is called.  After pressing any key, the main function returns 0
//				and ends the program.
//				
//				DEFAULT: This is called when the player puts in an invalid choice.
			
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

void menu();		//Prints the menu to the user
void game();		//Rolls X number of dice and asks the user if the next roll will be higher or lower
void credits();		//Prints the credits to the user

int total(vector<int> diceRoll);								//calculates the total of all dies in a set
bool results(int firstRoll, int secondRoll, int decision);		//calculates if the player guessed if the second set of die was higher, lower, or tie correctly
bool lower(int firstRoll, int secondRoll);						//calculates if the second roll is lower than the first roll
bool higher(int firstRoll, int secondRoll);						//calculates if the second roll is higher than the first roll
bool tie(int firstRoll, int secondRoll);						//calculates if both rolls resulted in a tie

void rollDie(int d, vector<int> &die, int offsetY);				//randomly rolls the player's amount of dice
void diceShell(int offsetX, int offsetY);						//draws the outer square border of the dice
void one(int offsetX, int offsetY);								//draw the One face	dots
void two(int offsetX, int offsetY);								//draw the Two face	dots
void three(int offsetX, int offsetY);							//draw the Three face dots
void four(int offsetX, int offsetY);							//draw the Four face dots
void five(int offsetX, int offsetY);							//draw the Five face dots
void six(int offsetX, int offsetY);								//draw the Six dots

void printResults(bool results);								//print the results of the game

void gotoXY(int x, int y);	//provided by the 2017 professor for intermediate programming, Chris Ziraldo 
							//this moves the cursor to the coordinates (X, Y)

//Game States
enum gameStates {
	GAME = 1,
	CREDITS,
	EXIT
};

//Game Results
enum conclusion {
	HIGHER = 1,
	LOWER,
	TIE
};

//MAIN FUNCTION
int main() {
	srand(time(NULL));
	int playerChoice;

	while (true) {
		menu();
		cin >> playerChoice;
		switch (playerChoice) {
		case GAME:
			game();
			break;
		case CREDITS:
			credits();
			system("pause");
			break;
		case EXIT:
			cout << "Good Bye!\n";
			system("pause");
			return 0;
			break;
		default:
			cout << "That is an invalid input.\n";
            system("pause");
			break;
		}
	}
}
//Prints the menu to the user
void menu() {
	system("CLS");
	cout << "**************************************************************************************\n";
	cout << "*                                    MAIN MENU                                       *\n";
	cout << "**************************************************************************************\n";
	cout << "*                                     WELCOME                                        *\n";
	cout << "*                              PLEASE SELECT AN OPTION                               *\n";
	cout << "**************************************************************************************\n";
	cout << "*               1)       PLAY GAME                                                   *\n";
	cout << "*               2)       CREDITS                                                     *\n";
	cout << "*               3)       EXIT                                                        *\n";
	cout << "**************************************************************************************\n";
}

//Rolls X number of dice and asks the user if the next roll will be higher or lower
void game() {
	int diceNumber;
	int first;
	int sec;
	int highLow;
	vector<int> fDieRoll;
	vector<int> sDieRoll;

	system("CLS");
	cout << "Choose the number of dice to play with: ";
	cin >> diceNumber;
	system("CLS");

	rollDie(diceNumber, fDieRoll, 0);

	gotoXY(0, 12);
	cout << "Total: " << total(fDieRoll) << "\n";
	cout << "**************************************************************************************\n";
	cout << "Will the next roll be higher lower, or tie \n";
	cout << "1 - Higher\n";
	cout << "2 - Lower\n";
	cout << "3 - Tie\n";
	cin >> highLow;

	rollDie(diceNumber, sDieRoll, 5);

	first = total(fDieRoll);
	sec   = total(sDieRoll);

	gotoXY(0, 18);
	cout << "**************************************************************************************\n";
	cout << "1st Roll: " << first << "\n";
	cout << "2nd Roll: " << sec << "\n";
	cout << "**************************************************************************************\n";
	printResults(results(first, sec, highLow));
	cout << "\n**************************************************************************************\n";
	cout << "\n";
	system("pause");
}

//Prints the credits to the user
void credits() {
	system("CLS");
	cout << "**************************************************************************************\n";
	cout << "*                                     CREDITS                                        *\n";
	cout << "**************************************************************************************\n";
	cout << "*PROJECT TITLE___________________________________________________________ASSIGNMENT 1*\n";
	cout << "*CREATED BY_____________________________________________________________TIFFANY WIEBE*\n";
	cout << "**************************************************************************************\n";
}

//calculates the total of all dies in a set
int total(vector<int> diceRoll) {
	int sum = 0;
	for (int i = 0; i < diceRoll.size(); i++) {
		sum += diceRoll[i];
	}
	return sum;
}

//calculates if the player guessed if the second set of die was higher, lower, or tie correctly
bool results(int firstRoll, int secondRoll, int decision) {
	if (lower(firstRoll, secondRoll)) {
		if (decision == LOWER) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (higher(firstRoll, secondRoll)) {
		if (decision == HIGHER) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (tie(firstRoll, secondRoll)) {
		if (decision == TIE) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		cout << "FUCK UP \n";
		return false;
	}

}

//calculates if the second roll is lower than the first roll
bool lower(int firstRoll, int secondRoll) {
	if (firstRoll > secondRoll) {
		return true;
	}
	return false;
}

//calculates if the second roll is higher than the first roll
bool higher(int firstRoll, int secondRoll) {
	if (firstRoll < secondRoll) {
		return true;
	}
	return false;
}

//calculates if both rolls resulted in a tie
bool tie(int firstRoll, int secondRoll) {
	if (firstRoll == secondRoll) {
		return true;
	}
	return false;
}

//print the results of the game
void printResults(bool results) {
	if (results) {
		cout << "WIN! ";
	}
	else if (!results) {
		cout << "Lose. ";
	}
}

//randomly rolls the player's amount of dice
void rollDie(int d, vector<int> &die, int offsetY) {
	int offsetX = 0;
	for (int i = 0; i < d; i++) {
		int dieNum = rand() % 6 + 1;
		die.push_back(dieNum);
		switch (dieNum) {
		case 1: // Dice Face 1
			one(offsetX, offsetY);
			diceShell(offsetX, offsetY);
			break;
		case 2:// Dice Face 2
			two(offsetX, offsetY);
			diceShell(offsetX, offsetY);
			break;
		case 3:// Dice Face 3
			three(offsetX, offsetY);
			diceShell(offsetX, offsetY);
			break;
		case 4:// Dice Face 4
			four(offsetX, offsetY);
			diceShell(offsetX, offsetY);
			break;
		case 5:// Dice Face 5
			five(offsetX, offsetY);
			diceShell(offsetX, offsetY);
			break;
		case 6:// Dice Face 6
			six(offsetX, offsetY);
			diceShell(offsetX, offsetY);
			break;
		}
		offsetX += 10;
	}
	cout << "\n";
}

//draws the outer square border of the dice
void diceShell(int offsetX, int offsetY) {
	int y = 0 + offsetY;

	gotoXY(offsetX, y);
	cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187;

	for (int i = 0; i < 3; i++) {
		y++;
		gotoXY(offsetX, y);
		cout << (char)186;
		gotoXY(offsetX + 8, y);
		cout << (char)186; 
	}

	gotoXY(offsetX, ++y);
	cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188;
}

//draw the One face	dots
void one(int offsetX, int offsetY) {
	gotoXY(offsetX + 4, offsetY + 2);
	cout << (char)254;
}

//draw the Two face	dots
void two(int offsetX, int offsetY) {
	gotoXY(offsetX + 2, offsetY + 1);
	cout << (char)254;
	gotoXY(offsetX + 6, offsetY + 3);
	cout << (char)254;
}

//draw the Three face dots
void three(int offsetX, int offsetY) {
	one(offsetX, offsetY);
	two(offsetX, offsetY);
}

//draw the Four face dots
void four(int offsetX, int offsetY) {
	two(offsetX, offsetY);

	gotoXY(offsetX + 6, offsetY + 1);
	cout << (char)254;
	gotoXY(offsetX + 2, offsetY + 3);
	cout << (char)254;
}

//draw the Five face dots
void five(int offsetX, int offsetY) {
	one(offsetX, offsetY);
	four(offsetX, offsetY);
}

//draw the Six face	dots
void six(int offsetX, int offsetY) {
	four(offsetX, offsetY);

	gotoXY(offsetX + 2, offsetY + 2);
	cout << (char)254 << (char)255 << (char)255 << (char)255 << (char)254;
}

//provided by the 2017 professor for intermediate programming 
//this moves the cursor to the coordinates (X, Y)
void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}