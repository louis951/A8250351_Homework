#include"Card.h"
#include"Bet.h"
#include<iostream>
#include<string>
#include <cstdlib> // 亂數相關函數 
#include <ctime>    //時間相關函數
using namespace std;

void endplay(Bet &Bet) {
	Bet.end();
}

int main() {
	int stake = 0, need = 1, i = 1;
	cout << "歡迎來到21點的世界，在這裡你可以盡情玩耍直到你的錢錢全部花光為止。" << endl;
	cout << "遊戲規則很簡單，A可以當成11或1(自動當11，除非A此時為11時會爆掉)、JQK等同於10點而其他點數就等同於他的數字。" << endl;
	cout << "在遊戲一點點賭注是一個刺激你獲勝的動力，而我們的規則是贏:壓多少贏兩倍 輸:壓多少輸多少，那我們就正式開始吧！" << endl;
	Card card;
	for (; need == 0 || need == 1 || need == 2;) {
		cout << "第" << card.getRound() << "局" << endl;
		card.input();
		system("CLS");
		cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
		card.Shuffle();
		if (i == 1)
			cout << "0不要牌 1要牌 2退出遊戲" << endl;

		i = 2;
		for (; i == 2 && card.getValueB() < 5;) {
			cin >> need;
			if (need == 1)
				card.askCardB();
			if (card.judgeSizeB() > 21)
				i = 0;
			if (need == 0 || need == 2)
				i = 0;
		}
		if (card.judgeSizeA() < 22 && card.judgeSizeB() < 22) {
			for (; card.getValueA() < 5 && card.judgeSizeA() < card.judgeSizeB();)
				card.askCardA();
		}
		endplay(card);
		if (need == 2)
			exit(0);
	}
}
