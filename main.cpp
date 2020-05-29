#include<iostream>
#include<time.h>
#include<string>
#include"card.h"
using namespace std;
int main()
{
	cout << "A超過21點時可視為1點，ＪＱＫ=10點,每人先發兩張牌,然後跟莊家比大小" << endl;//規則
	srand(time(NULL));
	int a1 = rand();
	int a2 = rand();
	a1 = a1 % 52+1;
	a2 = a2 % 52 + 1;//亂數
	/*要加a1=a2f防呆*/
	
	//判斷手牌顏色
	if (a1<= 13 && a1> 0)
		cout << '\6';
	else if (a1 > 13 && a1 <= 26)
		cout << '\3';
	else if (a1 > 26 && a1 <= 39)
		cout << '\4';
	else 
		cout << '\5';
	a1 %= 13+1;
	cout << a1<<endl;//第一副牌

	if (a2<= 13 && a2 > 0)
		cout << '\6';
	else if (a2 > 13 && a2 <= 26)
		cout << '\3';
	else if (a2 > 26 && a2 <= 39)
		cout << '\4';
	else
		cout << '\5';
	a2 %= 13+1;
	cout << a2<<endl;//第二副牌
	
	int cardNum = a1 + a2;//手牌相加

	Card cardNum1;
	cardNum1.sizeCard();//判斷手牌大小 要補int

	int money;
	cin >> money;
	Card money1;
	money1.input(money);//輸入賭金
	
	Card point;
	point.point();//結算金錢
	

	
	system("pause");









}