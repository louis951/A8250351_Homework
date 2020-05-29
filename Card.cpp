#ifndef Card_H
#define Card_H
#include<ctime>
#include<string>
#include<iostream>
#include <cstdlib>
using namespace std;

Card::Card() {
	srand(time(NULL));
	for (int i=0; i < 5; i++) {
		cardNumA[i] = 0;
		cardNumB[i] = 0;
	}
	money = 10000;
	char Suit[4] = { '\6','\3','\4','\5' };
	char cardName[13] = { 'A','2','3','4' ,'5' ,'6' ,'7' ,'8','9','10','J','Q','K' };
	int valueA[5] = {};
	int valueB[5] = {};
	for (int i = 0; i < 52; i++)
		card[i] = i % 13 + 1;//把牌變成只有1~13
	askCard12();
	int Card::judgeSizeA() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += cardNumA[i];
	}
	sum += 10;
	if (sum > 21) {
		sum -= 10;
	}
	if (sum > 21) {
		cout << "player win" << endl;
		way = true;
		point();
	}
	return sum;
}

}
