#ifndef Card_H
#define Card_H
#include<ctime>
#include<string>
#include<iostream>
#include <cstdlib> // 亂數相關函數 
#include <ctime>    //時間相關函數 
using namespace std;

class Card
{
public:
	Card();//
	void input();//投入賭注
	void Shuffle();//洗牌
	int judgeSizeA();//判斷牌的大小是否超過21點
	int judgeSizeB();
	void askCardB();//玩家要牌
	void askCardA();//莊家小於17點一定要加牌
	void askCard12();//發前兩張牌
	void printNowA();//印出當前牌數 莊家
	void printNowB();//印出當前牌數 玩家
	void point(); //結算金錢
	void end();//最後結算
	int getValueA();
	int getValueB();
	static int getRound();//第幾局
private:
	int card[53];//牌有52張
	int cardValue[53];//牌的數值
	string cardName[53];//牌的名子
	int cardrandom[53];//亂數數值
	int SuitrandomA[6] = {};//數值花色
	int SuitrandomB[6] = {};
	int valueA;//莊家牌數
	int valueB;
	int money;//你有多少錢，設定10000元
	int stake;//賭注
	int cardNumA[5];//莊家的手牌
	int cardNumB[5];//玩家的手牌
	static int round;
};
#endif
