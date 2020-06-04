#ifndef Bet_H
#define Bet_H
#include<iostream>
using namespace std;
class Bet {
public:
	Bet();
	int getMoney()const;
	int getStake()const;
	void setMoney(int);
	void setStake(int);
	virtual void end() = 0;
private:
	int money = 0;//你有多少錢
	int stake = 0;//賭注
};
#endif
