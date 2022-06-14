#pragma once
#include <iostream>
#define MAP_SIZE 15

using namespace std;

class TicTakToe {

private:
	bool isRunning;
	bool queue = false;
	int stepCounter;
	char map[MAP_SIZE] = {
			' ', '|', ' ', '|', ' ',
			' ', '|', ' ', '|', ' ',
			' ', '|', ' ', '|', ' '
	};
	string tutorMap = "0|2|4\n5|7|9\n10|12|14\n";

public:

	void showMap(char map[]); // отобразить все поле

	void menuInit(); //запуск и тд

	void fillMap(int position); //заполнить ячейку в поле по индексу

	void startGame(); // бесконечный цикл, пока isRunning = true

	void gameOver(); // конец игры в случае, когда есть победитель

	void nobodyWin(); // конец игры в случае, когда победителя нет

	void getState(char SYMBOL); // проверка на конец игры

};