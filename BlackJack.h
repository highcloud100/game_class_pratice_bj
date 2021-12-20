// #pragma once
#ifndef BlackJack_H
#define BlackJack_H

#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>


struct card
{
	int pat; // 패턴
	int num; // 숫자

};

class blackjack {


	int bet; 	  //베팅
	bool gameSet; //게임 끝났는지 
	int comCount; // 딜러 카드 개수
	int useCount; // 유저의 카드 개수
	int comSum;   // 합
	int useSum;	  // 합
	struct card* com; // 딜러의 카드
	struct card* use; // 유저의 카드
	static int allCoin;  //가져온 코인

public:

	blackjack() : comCount(2), useCount(2), comSum(0), useSum(0), gameSet(0) {
		std::cout << "BLACK JACK\n\n";
		com = new struct card[8]; // 카드 할당
		use = new struct card[8]; // 카드 할당
	}
	//=========================================================== 플레이
	void bust();   // 21 초과
	void comHit(); // 딜러 hit
	void useHit(); // 유저 hit
	void winer();  // 누가 이겼는지 판단
	void stop();    // 딜러 hit, 점수계산
	void sum();    // 카드 숫자 합

	//=========================================================== 메카니즘
	void table(); //초기 태이블
	void table(int x); // 유저 hit table
	void table(int x, int y); // 딜러 hit table
	bool cardcheck(struct card* card1, struct card* card2);
	void shuffle();
	char readNum(int x); // 정수를 카드 모양으로 해석
	char readPat(int x);

	//===========================================================게임 끝 판단
	bool getSet() {
		return gameSet;
	}
	//-----------------------------------------------------------돈 계산


	static void setallCoin(int x) {
		allCoin = x;
	}

	int getallCoin() {
		return allCoin;
	}

	int getbet() {
		return bet;
	}

	void betCoin(int betCoin) {  // 베팅
		if (betCoin > allCoin || betCoin % 10 != 0) {
			exit(0);
		}
		allCoin -= betCoin;
		bet = betCoin;
	}

	void Result(int seed, int how) { // 10단위 투자 금액=bet, 블랙잭인지 졌는지 이겼는지
		if (how == 0) {
			allCoin += seed + seed * 1.5;
			bet = 0;
		}
		else if (how == 1) { //이김
			allCoin += seed * 2;
			bet = 0;
		}
		else if (how == 2) {
			bet = 0;
			return;
		}
		else {
			allCoin += bet;
			bet = 0;
		}

	}  // 베팅 한거 계산

	~blackjack() {
		system("cls");  //테이블 정리 -> cmd 초기화
		delete[] com;
		delete[] use;
	}
};

#endif
