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
	void judgeSize();//判斷牌的大小是否超過21點
	void askCard();//玩家要牌
	void sizeCard();//判斷手排大小
	void pass();//是否有五張直接獲勝
	void point(); //結算金錢
private:
	int card[53];//牌有53張
	int Suit[4] = { '\6','\3','\4','\5' };//花色
	int value[53];//牌的數值,設定1-11(A可為11 JQK為10)
	int money = 10000;//你有多少錢，設定10000元
	int stake;//賭注
	int cardNumA[5] = { 0,0,0,0,0 };//莊家的手牌
	int cardNumB[5] = { 0,0,0,0,0 };//玩家的手牌
	bool way;//判斷輸贏
};
#endif