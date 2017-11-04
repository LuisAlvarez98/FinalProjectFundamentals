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
void update() {
	bool cont = true;
	int numSelect;
	char option;

	while (cont == true) {
		showBoard();
		cont = false;
	}
}
int main()
{
	fillBoard();
	update();
    return 0;
}

