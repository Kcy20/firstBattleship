﻿// battleshipProject.cpp 
//Kevin Yang 
// Quick game of battleship without using classes or OOP methods.

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctype.h>

using namespace std;

char board[4][4];
const int shipSize = 2;

void initBoard();
void placeShip();
void displayBoard();
bool checkPlay(char[3]);

// Use these for the ship values
int shipX1, shipY1, shipX2, shipY2;
bool ship[shipSize] = { true, true };
char play[3];
int moves = 0;

//Main method
int main(int argc, const char * argv[]) 
{
	// Let's call our functions and play the game!
	cout << "Welcome to the WOPR Game of Battleship" << std::endl;
	initBoard();
	displayBoard();
	placeShip();
	// Show where the ship is for debugging.
	//std::cout << "Ship was placed at (" << shipX1+1 << "," << shipY1+1 << ")(" << shipX2+1 << "," << shipY2+1 << ")" << endl; 
	std::cout << "Enter your attack cordinates! ";
	std::cin >> play;

	// while loop to check the plays
	while (!checkPlay(play))
	{
		cout << "Time for another attack: [" << moves << "] ";
		cin >> play;
	}
	std::cout << "Congrats! You beat the computer in " << moves << " moves!" << std::endl;

	return 0;

}

//Initialize the board
void initBoard()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][i] = ' ';
		}
	}
}


//Place the ship
void placeShip()
{
	srand((unsigned int)time(NULL));
	shipX1 = rand() % 4;

	//check ship is not placed out of the board horizontally
	if (shipX1 == 3)
	{
		shipX1--;
	}
	shipY1 = rand() % 4;

	shipX2 = shipX1 + 1;
	shipY2 = shipY1;
}


//check the play and also see if there is a winner (change the return type)
bool checkPlay(char play[3])
{
	int x = tolower(play[0]) - 'a';
	int y = play[1] - '0' - 1;

	if (ship[0] && x == shipX1 && y == shipY1)
	{
		ship[0] = false;
		board[y][x] = 'X';
		cout << "Thats a hit!" << endl;
	}
	else if (ship[1] && x == shipX2 && y == shipY2)
	{
		ship[1] = false;
		board[y][x] = 'X';
		cout << "Thats a hit!" << endl;
	}
	else
	{
		board[y][x] = '*';
		if (moves == 0)
		{
			cout << "You missed!" << endl;
		}
		else
		{
			cout << "You missed! (again!! Please Aim!!)" << endl;
		}
	}
	moves++;

	displayBoard();

	if (!ship[0] && !ship[1])
	{
		return true;
	}

	return false;
}


//Display the board here
void displayBoard()
{
	cout << "  A B C D" << endl;
	for (int i = 1; i < 5; i++)
	{
		cout << i << " ";
		for (int j = 1; j < 5; j++)
		{
			cout << board[i - 1][j - 1] << " ";
		}
		cout << endl;
	}
}
