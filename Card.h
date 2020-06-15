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

template <typename T>
class Card : public Bet{
public:
	Card();//
	void input();//投入賭注
	void Shuffle();//洗牌
	T judgeSizeA();//判斷牌的大小是否超過21點
	T judgeSizeB();
	void askCardB();//玩家要牌
	void askCardA();//莊家小於17點一定要加牌
	void askCard12();//發前兩張牌
	void printNowA();//印出當前牌數 莊家
	void printNowB();//印出當前牌數 玩家
	void point()const; //結算金錢
	void end();//最後結算
	T getValueA();
	T getValueB();
	static int getRound();//第幾局
private:
	vector<T> card;//牌有52張
	vector<T> cardValue;//牌的數值
	string cardName[53];;//牌的名子
	vector<T> cardrandom;//亂數數值
	vector<T> SuitrandomA;//數值花色
	vector<T> SuitrandomB;
	T valueA;//莊家牌數
	T valueB;
	vector<T> cardNumA;//莊家的手牌
	vector<T> cardNumB;//玩家的手牌
	static int round;
};
#endif
