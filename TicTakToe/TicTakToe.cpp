#include "TicTakToe.h"

void TicTakToe::showMap(char map[]) {
	for (int i = 0; i < MAP_SIZE; i++) {
		if (i == 5 || i == 10 || i == 15) {
			cout << endl;
			cout << map[i];
		}
		else {
			cout << map[i];
		}
	}
	cout << endl;
}

void TicTakToe::menuInit() {
	cout << "TikTakToe v0.1" << endl;
	cout << "Press 1 to start: " << endl;
	int choose = 0;
	cin >> choose;
	switch (choose) {
	case 1:
		startGame();
		break;
	default:
		cerr << "Press 1 to start: " << endl;
		break;
	}
}

void TicTakToe::fillMap(int position) {
	if (queue == false) {
		map[position] = 'X';
		showMap(map);
	}
	else {
		map[position] = 'O';
		showMap(map);
	}
}

void TicTakToe::startGame() {
	cout << tutorMap;
	stepCounter = 0;
	isRunning = true;
	int position = 0;
	while (isRunning) {
		if (queue == false) {
			cout << "Enter position of X : ";
			cin >> position;
			fillMap(position);
			queue = true;
			getState('X');

		}
		else if (queue == true) {
			cout << "Enter position of O : ";
			cin >> position;
			fillMap(position);
			queue = false;
			getState('O');
		}
	}
}

void TicTakToe::gameOver() {
	isRunning = false;
	if (queue == false) {
		cout << "O wins" << endl;
	}
	else
		cout << "X wins" << endl;
}

void TicTakToe::nobodyWin() {
	isRunning = false;
	cout << "Nobody win." << endl;
}

void TicTakToe::getState(char SYMBOL) {
	if (map[0] == SYMBOL && map[2] == SYMBOL && map[4] == SYMBOL) {
		gameOver();
	}
	else if (map[5] == SYMBOL && map[7] == SYMBOL && map[9] == SYMBOL) {
		gameOver();
	}
	else if (map[10] == SYMBOL && map[12] == SYMBOL && map[14] == SYMBOL) {
		gameOver();
	}
	else if (map[0] == SYMBOL && map[5] == SYMBOL && map[10] == SYMBOL) {
		gameOver();
	}
	else if (map[2] == SYMBOL && map[7] == SYMBOL && map[12] == SYMBOL) {
		gameOver();
	}
	else if (map[4] == SYMBOL && map[9] == SYMBOL && map[14] == SYMBOL) {
		gameOver();
	}
	else if (map[0] == SYMBOL && map[7] == SYMBOL && map[14] == SYMBOL) {
		gameOver();
	}
	else if (map[4] == SYMBOL && map[7] == SYMBOL && map[10] == SYMBOL) {
		gameOver();
	}
	else if (map[0] != ' ' && map[2] != ' ' && map[4] != ' ' && map[5] != ' ' && map[7] != ' ' && map[9] != ' ' && map[10] != ' ' && map[12] != ' ' && map[14] != ' ' && isRunning == true) {
		nobodyWin();
	}
}