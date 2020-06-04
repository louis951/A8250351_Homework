#include<iostream>
#include"Bet.h"
using namespace std;
Bet::Bet() {
	
}
int Bet::getMoney()const {
	return money;
}
int Bet::getStake()const {
	return stake;
}
void Bet::setMoney(int _money) {
	money += _money;
}
void Bet::setStake(int stake) {
	this->stake = stake;
}
