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
void Card::Shuffle() {
	card[0] = 0;
	for (int i = 1; i < 14; i++) {
		card[i] = i;
		card[i + 13] = i;
		card[i + 26] = i;
		card[i + 39] = i;
	}

	for (int i = 0; i < 53; i++) {
		cardrandom[i] = card[i];
	}

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

	valueA = 0;
	valueB = 0;
	for (int i = 0; i < 5; i++) {
		cardNumA[i] = 0;
		cardNumB[i] = 0;
	}
	srand(time(NULL));
	round++;
	askCard12();
	printNowA();
	printNowB();
}
void Card::input() {
	cout << "請下注" << endl;
	cin >> stake;
	for (; stake <= 0 || stake > money;) {
		cout << "你下注金錢錯誤 請勿超過持有錢錢 請勿下注負數" << endl;
		cin >> stake;
	}
	this->stake = stake;
}
int Card::judgeSizeA() {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < valueA; i++) {
		sum += cardValue[cardNumA[i]];
		if (cardValue[cardNumA[i]] == 1) {
			count++;
		}
	}
	if (sum <= 11 && count > 0) {
		sum += 10;
	}
	return sum;
}
int Card::judgeSizeB() {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < valueB; i++) {
		sum += cardValue[cardNumB[i]];
		if (cardValue[cardNumB[i]] == 1) {
			count++;
		}
	}
	if (sum <= 11 && count > 0) {
		sum += 10;
	}
	return sum;
}
void Card::point() {
	if (money <= 0) {
		cout << "你沒錢了,請問是否要賣屁股給資工1B吳佳凱獲得更多金錢？" << endl;
		exit(0);
	}
	else
		cout << money << endl;
}
int Card::getValueA() {
	return valueA;
}
int Card::getValueB() {
	return valueB;
}
