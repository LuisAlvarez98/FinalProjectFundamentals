/*
	Tarea Integradora
	11/4/2017
	Por Luis Felipe Alvarez Sanchez A01194173

*/
#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

char board[4][4];
bool validator = true;
int xPos, yPos;

//Obtains the position of the object
void position(int index) {
	int counter = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			counter++;
			if (counter == index) {
				xPos = i;
				yPos = j;
			}
			
		}
	}
}
//Moves the piece
void movement(char move) {
	switch (move) {
	case 'w':
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[xPos - 1][yPos] == '*') {
					board[xPos][yPos] = ' ';
					board[xPos - 1][yPos] = ' ';
					board[xPos - 2][yPos] = '*';
				}
			}
		}
		break;
	case 'a':
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[xPos][yPos - 1] == '*') {
					board[xPos][yPos] = ' ';
					board[xPos][yPos - 1] = ' ';
					board[xPos][yPos - 2] = '*';
				}
			}
		}
		break;
	case 's':
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[xPos + 1][yPos] == '*') {
					board[xPos][yPos] = ' ';
					board[xPos + 1][yPos] = ' ';
					board[xPos + 2][yPos] = '*';
				}
			}
		}
		break;
	case 'd':
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[xPos][yPos + 1] == '*') {
					board[xPos][yPos] = ' ';
					board[xPos][yPos + 1] = ' ';
					board[xPos][yPos + 2] = '*'; 
				}
			}
		}
		break;
	}
}
//Fill outs the board
void fillBoard() {
	int counter, i , j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			board[i][j] = ' ';
		}
	}
	srand((int)time(0));
	for (counter = 1; counter <= 13;) {
		i = rand() % 4;
		j = rand() % 4;
		if (board[i][j] == ' ') {
			board[i][j] = '*';
			counter++;
		}
	}

}
//Shows the game board
void showBoard() {
	int counter = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << '[' <<board[i][j] << ']' <<  " ";
			counter++;
		}
		cout << " "<<"\n";
	}
}
//Main loop of the game
void update() {
	bool cont = true;
	int numSelect;
	char option;
	char move;
	//Fills out the board
	fillBoard();
	showBoard();
	//Main loop
	while (cont == true) {
		cout << "Casilla: ";
		cin >> numSelect;
		position(numSelect);
		cout << "(a - izq; s - aba; w - arr; d - der)" << "\n";
		cin >> move;
		movement(move);
		showBoard();
		cout << "Seguir (s/n)";
		cin >> option;
		if (tolower(option) == 'n') {
			cont = false;
		}
	}
}
//Main function
int main()
{
	update();	

    return 0;
}

