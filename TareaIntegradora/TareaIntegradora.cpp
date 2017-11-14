/*
	Tarea Integradora
	11/4/2017
	Por Luis Felipe Alvarez Sanchez A01194173
	ver limitess

*/
#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include<iomanip>
using namespace std;

char board[4][4];
bool validator = true;
int xPos, yPos;
int pieceCount = 13;
char option;


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
				if (board[xPos - 1][yPos] == '*' && board[xPos - 2][yPos] == ' ' ){
					board[xPos][yPos] = ' ';
					board[xPos - 1][yPos] = ' ';
					board[xPos - 2][yPos] = '*';
					pieceCount--;
				}
			}
		}
		break;
	case 'a':
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[xPos][yPos - 1] == '*' && board[xPos][yPos - 2] == ' '){
					if ((yPos - 2) < 0) {
						break;
					}else {
						board[xPos][yPos] = ' ';
						board[xPos][yPos - 1] = ' ';
						board[xPos][yPos - 2] = '*';
						pieceCount--;
					}
						
				}
			}
		}
		break;
	case 's':
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[xPos + 1][yPos] == '*' && board[xPos + 2][yPos] == ' ') {
					board[xPos][yPos] = ' ';
					board[xPos + 1][yPos] = ' ';
					board[xPos + 2][yPos] = '*';
					pieceCount--;
				}
			}
		}
		break;
	case 'd':
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[xPos][yPos + 1] == '*' && board[xPos][yPos + 2] == ' '){
					if (yPos + 2 > 3) {
						break;
					}else{
						board[xPos][yPos] = ' ';
						board[xPos][yPos + 1] = ' ';
						board[xPos][yPos + 2] = '*';
						pieceCount--;
					}
				
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
			cout <<left << setw(2) <<counter << '[' <<board[i][j] << ']' << " " ;
			counter++;
		}
		cout <<"\n";
	}
}
//Main loop of the game
void update() {
	bool cont = true;
	int numSelect;
	char move;
	//Fills out the board
	fillBoard();
	showBoard();
	//Main loop
	while (cont == true) {
			//pide casilla
		do {
			cout << "Casilla: " << "\n";
			cin >> numSelect;
			position(numSelect);
		} while (!(numSelect >= 1 && numSelect <= 16));
			//pide movimiento
			while (true) {
				cout << "(a - izq; s - aba; w - arr; d - der)" << "\n";
				cin >> move;
				movement(tolower(move));
				if (cin.fail()) { 
					cin.clear(); 
					cin.ignore(1000, '\n'); 
					continue;
				}
				if (!(tolower(move) == 'w' || tolower(move) == 'a' || tolower(move) == 's' || tolower(move) == 'd'))
					continue;

				break;
			}
			showBoard();
			while (true) {
				cout << "Seguir (s/n)";
				cin >> option;
				if (cin.fail()) {
					cin.clear(); 
					cin.ignore(1000, '\n'); 
					continue;
				}
				if (!(tolower(option) == 's' || tolower(option) == 'n')) 
					continue;
				break;
			}
			
			if (tolower(option) == 'n') {
				cont = false;
			}
			else if (pieceCount == 1) {
				cont = false;
				cout << "Haz ganado :)" << "\n";
			}
	}
}
//Main function
int main()
{
	update();	
    return 0;
}

