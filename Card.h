#ifndef Card_H
#define Card_H
#include<ctime>
#include<string>
#include<iostream>
using namespace std;

class Card
{
public:
	Card();//
	void input(int);//投入賭注
	void Shuffle();//洗牌
	int judgeSizeA();//判斷牌的大小是否超過21點
	int judgeSizeB();
	void askCard();//玩家要牌
	void sizeCard();//判斷手牌大小
	void pass();//是否有五張直接獲勝
	void askCard12();////發前兩張牌
	void point(); //結算金錢
private:
	int card[52];//牌有52張
	char cardName[13];//知道當前牌是什麼 比如AJQK這種顯示出來
	char Suit[4];//花色
	int valueA[5];//牌的數值
	int valueB[5];
	int money;//你有多少錢，設定10000元
	int stake;//賭注
	int cardNumA[5];//莊家的手牌
	int cardNumB[5];//玩家的手牌
	bool way;//判斷輸贏
};
#endif
