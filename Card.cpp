#include"Card.h"
#include<iostream>
#include"Bet.h"
#include<ctime>
#include<string>
#include<iomanip>
#include<vector>
#include <cstdlib> // 亂數相關函數 
#include <ctime>    //時間相關函數 
using namespace std;
int Card::round = 0;
int Card::getRound() {
	return round;
}
Card::Card() {
	for (int i = 0; i < 53; i++) {
		card.push_back(i);
		cardrandom.push_back(i);
	}

	cardValue.push_back(0);
	for (int i = 1; i < 53; i++) {
		if (card[i] <= 10)
			cardValue.push_back(card[i]);
		else
			cardValue.push_back(10);
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

	setMoney(10000);
	setStake(0);

	valueA = 0;
	valueB = 0;
	for (int i = 0; i < 5; i++) {
		cardNumA.push_back(0);
		cardNumB.push_back(0);
	}

	for (int i = 0; i < 6; i++) {
		SuitrandomA.push_back(0);
		SuitrandomB.push_back(0);
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
			cardValue[i] = card[i];
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

	for (int i = 0; i < 6; i++) {
		SuitrandomA[i] = 0;
		SuitrandomB[i] = 0;
	}

	srand(time(NULL));
	round++;
	askCard12();
	printNowA();
	printNowB();
}
void Card::input()  {
	int stake = 0;
	cout << "請下注" << endl;
	cin >> stake;
	setStake(stake);
	for (; getStake() <= 0 || getStake() > getMoney();) {
		cout << "你下注金錢錯誤 請勿超過持有錢錢 請勿下注負數" << endl;
		cin >> stake;
		setStake(stake);
	}
}
int Card::judgeSizeA() const {
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
int Card::judgeSizeB() const {
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
void Card::point() const {
	if (getMoney() <= 0) {
		cout << "你沒錢了,請問是否要賣屁股給資工1B吳佳凱獲得更多金錢？" << endl;
		exit(0);
	}
	else
		cout <<"現有金錢: "<< getMoney() << endl;
}
int Card::getValueA() const {
	return valueA;
}
int Card::getValueB() const {
	return valueB;
}
void Card::askCardA() {
	int sum = 0;
	sum = judgeSizeA();
	int randomValue = 0, x = 1;
	for (; x == 1;) {
		randomValue = rand() % 52 + 1;
		if (cardrandom[randomValue] != 0) {
			cardNumA[valueA] = cardrandom[randomValue];
			cardrandom[randomValue] = 0;
			x--;
			valueA++;
			SuitrandomA[valueA] = randomValue;
			printNowA();
			sum = judgeSizeB();
		}
	}
}
void Card::askCardB() {
	int sum = 0;
	sum = judgeSizeB();
	int randomValue = 0, x = 1;
	if (sum <= 21) {
		for (; x == 1;) {
			randomValue = rand() % 52 + 1;
			if (cardrandom[randomValue] != 0) {
				cardNumB[valueB] = cardrandom[randomValue];
				cardrandom[randomValue] = 0;
				x--;
				valueB++;
				SuitrandomB[valueB] = randomValue;
				printNowB();
				sum = judgeSizeB();
			}
		}
	}
}
void Card::askCard12() {
	int randomValue = 0, x = 1;
	for (; x == 1;) {
		randomValue = rand() % 52 + 1;
		if (valueA < 2 && cardrandom[randomValue] != 0) {
			cardNumA[valueA] = cardrandom[randomValue];
			cardrandom[randomValue] = 0;
			valueA++;
			SuitrandomA[valueA] = randomValue;
		}
		else if (valueB < 2 && cardrandom[randomValue] != 0) {
			cardNumB[valueB] = cardrandom[randomValue];
			cardrandom[randomValue] = 0;
			valueB++;
			SuitrandomB[valueB] = randomValue;
		}
		if (valueA == 2 && valueB == 2) {
			x--;
		}
	}
}
void Card::printNowA() const {
	cout << "莊家目前手牌: ";
	for (int i = 0, j = 1; i < valueA; i++, j++) {
		if (SuitrandomA[j] <= 13)
			cout << "黑桃";
		else if (13 < SuitrandomA[j] && SuitrandomA[j] <= 26)
			cout << "愛心";
		else if (26 < SuitrandomA[j] && SuitrandomA[j] <= 39)
			cout << "方塊";
		else if (39 < SuitrandomA[j] && SuitrandomA[j] <= 52)
			cout << "梅花";
		cout << cardName[cardNumA[i]] << " ";
	}
	cout << setw(2) << fixed << "手上點數: " << judgeSizeA();
	cout << endl;
}
void Card::printNowB() const {
	cout << "玩家目前手牌: ";
	for (int i = 0, j = 1; i < valueB; i++, j++) {
		if (SuitrandomB[j] <= 13)
			cout << "黑桃";
		else if (13 < SuitrandomB[j] && SuitrandomB[j] <= 26)
			cout << "愛心";
		else if (26 < SuitrandomB[j] && SuitrandomB[j] <= 39)
			cout << "方塊";
		else if (39 < SuitrandomB[j] && SuitrandomB[j] <= 52)
			cout << "梅花";
		cout << cardName[cardNumB[i]] << " ";
	}
	cout <<setw(2)<<fixed<< "手上點數: " << judgeSizeB();
	cout << endl;
}
void Card::end()  {
	cout << endl;
	cout << "開始結算" << endl;
	if (valueB == 5 && judgeSizeB() <= 21) {
		printNowA();
		printNowB();
		cout << "恭喜玩家過五關獲得勝利" << endl;
		setMoney(getStake() * 2);
		point();
	}
	else if (valueA == 5 && judgeSizeA() <= 21) {
		printNowA();
		printNowB();
		cout << "算你雖小莊家過五關你輸了" << endl;
		setMoney(-getStake());
		point();
	}
	else if (judgeSizeB() > 21) {
		printNowA();
		printNowB();
		cout << "你超過21點你爆了" << endl;
		setMoney(-getStake());
		point();
	}
	else if (judgeSizeA() > 21) {
		printNowA();
		printNowB();
		cout << "莊家超過21點莊家爆了" << endl;
		setMoney(getStake() * 2);
		point();
	}
	else if (judgeSizeA() < judgeSizeB()) {
		printNowA();
		printNowB();
		cout << "你贏了" << endl;
		setMoney(getStake() * 2);
		point();
	}
	else if (judgeSizeA() == judgeSizeB()) {
		printNowA();
		printNowB();
		cout << "平手" << endl;
		point();
	}
	else {
		printNowA();
		printNowB();
		cout << "你輸了" << endl;
		setMoney(-getStake());
		point();
	}
	cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
}
