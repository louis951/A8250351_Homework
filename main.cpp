#include"Card.h"
#include<iostream>
#include<string>
#include <cstdlib> // 亂數相關函數 
#include <ctime>    //時間相關函數
using namespace std;
int main() {
	cout << "歡迎來到21點的世界，在這裡你可以盡情玩耍直到你的錢錢全部花光為止。" << endl;
	cout << "遊戲規則很簡單，A可以當成11或1(自動當11，除非A此時為11時會爆掉)、JQK等同於10點而其他點數就等同於他的數字。" << endl;
	cout << "在遊戲一點點賭注是一個很棒的調適，而我們的規則是贏:壓多少贏多少 輸:壓多少輸多少，那我們就正式開始吧！" << endl;
	Card card;
}
