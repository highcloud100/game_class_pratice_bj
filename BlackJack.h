// #pragma once
#ifndef BlackJack_H
#define BlackJack_H

#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>


struct card
{
	int pat; // ����
	int num; // ����

};

class blackjack {


	int bet; 	  //����
	bool gameSet; //���� �������� 
	int comCount; // ���� ī�� ����
	int useCount; // ������ ī�� ����
	int comSum;   // ��
	int useSum;	  // ��
	struct card* com; // ������ ī��
	struct card* use; // ������ ī��
	static int allCoin;  //������ ����

public:

	blackjack() : comCount(2), useCount(2), comSum(0), useSum(0), gameSet(0) {
		std::cout << "BLACK JACK\n\n";
		com = new struct card[8]; // ī�� �Ҵ�
		use = new struct card[8]; // ī�� �Ҵ�
	}
	//=========================================================== �÷���
	void bust();   // 21 �ʰ�
	void comHit(); // ���� hit
	void useHit(); // ���� hit
	void winer();  // ���� �̰���� �Ǵ�
	void stop();    // ���� hit, �������
	void sum();    // ī�� ���� ��

	//=========================================================== ��ī����
	void table(); //�ʱ� ���̺�
	void table(int x); // ���� hit table
	void table(int x, int y); // ���� hit table
	bool cardcheck(struct card* card1, struct card* card2);
	void shuffle();
	char readNum(int x); // ������ ī�� ������� �ؼ�
	char readPat(int x);

	//===========================================================���� �� �Ǵ�
	bool getSet() {
		return gameSet;
	}
	//-----------------------------------------------------------�� ���


	static void setallCoin(int x) {
		allCoin = x;
	}

	int getallCoin() {
		return allCoin;
	}

	int getbet() {
		return bet;
	}

	void betCoin(int betCoin) {  // ����
		if (betCoin > allCoin || betCoin % 10 != 0) {
			exit(0);
		}
		allCoin -= betCoin;
		bet = betCoin;
	}

	void Result(int seed, int how) { // 10���� ���� �ݾ�=bet, �������� ������ �̰����
		if (how == 0) {
			allCoin += seed + seed * 1.5;
			bet = 0;
		}
		else if (how == 1) { //�̱�
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

	}  // ���� �Ѱ� ���

	~blackjack() {
		system("cls");  //���̺� ���� -> cmd �ʱ�ȭ
		delete[] com;
		delete[] use;
	}
};

#endif
