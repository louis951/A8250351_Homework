#ifndef Card_H
#define Card_H
#include<ctime>
#include<string>
#include"Bet.h"
#include<iostream>
#include<vector>
#include <cstdlib> // 亂數相關函數 
#include <ctime>    //時間相關函數 
using namespace std;

class Card : public Bet{
public:
	Card();//
	void input();//投入賭注
	void Shuffle();//洗牌
	int judgeSizeA()const;//判斷牌的大小是否超過21點
	int judgeSizeB()const;
	void askCardB();//玩家要牌
	void askCardA();//莊家小於17點一定要加牌
	void askCard12();//發前兩張牌
	void printNowA()const;//印出當前牌數 莊家
	void printNowB()const;//印出當前牌數 玩家
	void point()const; //結算金錢
	void end();//最後結算
	int getValueA()const;
	int getValueB()const;
	static int getRound();//第幾局
private:
	vector<int> card;//牌有52張
	vector<int> cardValue;//牌的數值
	string cardName[53];;//牌的名子
	vector<int> cardrandom;//亂數數值
	vector<int> SuitrandomA;//數值花色
	vector<int> SuitrandomB;
	int valueA;//莊家牌數
	int valueB;
	vector<int> cardNumA;//莊家的手牌
	vector<int> cardNumB;//玩家的手牌
	static int round;
};
#endif
