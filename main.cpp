#include<iostream>
#include<time.h>
#include<string>
#include"card.h"
using namespace std;
int main()
{
	cout << "A�W�L21�I�ɥi����1�I�A�آߢ�=10�I,�C�H���o��i�P,�M�����a��j�p" << endl;//�W�h
	srand(time(NULL));
	int a1 = rand();
	int a2 = rand();
	a1 = a1 % 52+1;
	a2 = a2 % 52 + 1;//�ü�
	/*�n�[a1=a2f���b*/
	
	//�P�_��P�C��
	if (a1<= 13 && a1> 0)
		cout << '\6';
	else if (a1 > 13 && a1 <= 26)
		cout << '\3';
	else if (a1 > 26 && a1 <= 39)
		cout << '\4';
	else 
		cout << '\5';
	a1 %= 13+1;
	cout << a1<<endl;//�Ĥ@�ƵP

	if (a2<= 13 && a2 > 0)
		cout << '\6';
	else if (a2 > 13 && a2 <= 26)
		cout << '\3';
	else if (a2 > 26 && a2 <= 39)
		cout << '\4';
	else
		cout << '\5';
	a2 %= 13+1;
	cout << a2<<endl;//�ĤG�ƵP
	
	int cardNum = a1 + a2;//��P�ۥ[

	Card cardNum1;
	cardNum1.sizeCard();//�P�_��P�j�p �n��int

	int money;
	cin >> money;
	Card money1;
	money1.input(money);//��J���
	
	Card point;
	point.point();//�������
	

	
	system("pause");









}