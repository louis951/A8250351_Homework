#ifndef Card_H
#define Card_H
#include<ctime>
#include<string>
#include<iostream>
#include <cstdlib>
using namespace std;

int Card::round = 0;
int Card::getRound() {
	return round;
}
Card::Card() {
	card[0] = 0;
	for (int i = 1; i < 14; i++) {
		card[i] = i;
		card[i + 13] = i;
		card[i + 26] = i;
		card[i + 39] = i;
	}

	for (int i = 0; i < 53; i++) 
		cardrandom[i] = card[i];

	cardValue[0] = 0;
	for (int i = 1; i < 53; i++) {
		if (card[i] <= 10)
			cardValue[i] = i;
		else
			cardValue[i] = 10;
	}

	cardName[0] = "";
	for (int i = 0; i < 4; i++) {
		cardName[1 + i * 13] = "A";
		cardName[2 + i * 13] = "2";
		cardName[3 + i * 13] = "3";
		cardName[4 + i * 13] = "4";
		cardName[5 + i * 13] = "5";
		cardName[6 + i * 13] = "6";
		cardName[7 + i * 13] = "7";
		cardName[8 + i * 13] = "8";
		cardName[9 + i * 13] = "9";
		cardName[10 + i * 13] = "10";
		cardName[11 + i * 13] = "J";
		cardName[12 + i * 13] = "Q";
		cardName[13 + i * 13] = "K";
	}

	money = 10000;
	stake = 0;

	valueA = 0;
	valueB = 0;
	for (int i = 0; i < 5; i++) {
		cardNumA[i] = 0;
		cardNumB[i] = 0;
	}

	srand(time(NULL));
	round++;
}
