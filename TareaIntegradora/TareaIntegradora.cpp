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
//Obtains the position of the object
void position(int index) {
	int counter = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			counter++;
			if (counter == index) {
				cout << " " << i << " " << j << "\n";
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
				board[0][0] = ' ';
				board[1][0] = ' ';
				board[0 + 2][0] = '*';
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

	while (cont == true) {
		showBoard();
		cont = false;
	}
}
//Main function
int main()
{
	fillBoard();
	update();
	cout << "---------------" << "\n";
	position(2);
    return 0;
}

