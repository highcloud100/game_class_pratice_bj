#include "BlackJack.h"

int blackjack::allCoin = 0;

void blackjack::table() {
	// 딜러 출력
	int size = 1;
	std::cout << "\nCOIN: " << getallCoin() << " BET: " << getbet() << std::endl;
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("│ %c  │ ", readPat(com[i].pat));
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("│    │ ");
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("│   %c│ ", readNum(com[i].num));
	}
	printf("\n");
	//============================
	printf("\n");
	printf("\n");
	//============================
	//유저 출력
	size = useCount;
	for (int i = 0; i < size; i++) {
		printf("│ %c  │ ", readPat(use[i].pat));
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("│    │ ");
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("│   %c│ ", readNum(use[i].num));
	}
	printf("\n");

	// 블랙잭 판단
	this->sum();
	if (21 == useSum) {
		std::cout << "\n================================\nBLACK JACK!!\n================================\nYOU WIN\n";
		gameSet = 1;
		Result(bet, 0);
	}

}

void blackjack::table(int x) {
	// 딜러 출력
	int size = 1;
	std::cout << "\nCOIN: " << getallCoin() << " BET: " << getbet() << std::endl;
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("│ %c  │ ", readPat(com[i].pat));
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("│    │ ");
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("│   %c│ ", readNum(com[i].num));
	}
	printf("\n");
	//============================
	printf("\n");
	printf("\n");
	//============================
	//유저 출력
	size = useCount;
	for (int i = 0; i < size; i++) {
		printf("│ %c  │ ", readPat(use[i].pat));
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("│    │ ");
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("│   %c│ ", readNum(use[i].num));
	}
	printf("\n");

}

void blackjack::table(int x, int y) {
	// 딜러 출력
	int size = comCount;
	std::cout << "\nCOIN: " << getallCoin() << " BET: " << getbet() << std::endl;
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("│ %c  │ ", readPat(com[i].pat));
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("│    │ ");
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("│   %c│ ", readNum(com[i].num));
	}
	printf("\n");
	//============================
	printf("\n");
	printf("\n");
	//============================
	//유저 출력
	size = useCount;
	for (int i = 0; i < size; i++) {
		printf("│ %c  │ ", readPat(use[i].pat));
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("│    │ ");
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("│   %c│ ", readNum(use[i].num));
	}
	printf("\n");

}

void blackjack::shuffle() { // 초기 2장씩 설정


	/*for (int i = 0; i < comCount; i++) {
		while (1) {
			bool flag = 0;
			com[i].num = rand() % 13 + 1;
			com[i].pat = rand() % 4;
			if (i == 0) {
				comCount++;
				break;
			}
			for (int j = 0; j < i; j++) {
				if (cardcheck(&com[i], &com[j])) flag = 1;
			}

			if (flag) {
				comCount++;
				break;
			}
		}
	}*/
	com[0].num = rand() % 13 + 1;
	com[0].pat = rand() % 4;

	while (1) {
		com[1].num = rand() % 13 + 1;
		com[1].pat = rand() % 4;
		if (cardcheck(&com[0], &com[1])) {
			break;
		}
	}

	while (1) {
		use[0].num = rand() % 13 + 1;
		use[0].pat = rand() % 4;

		if (cardcheck(&com[0], &use[0]) && cardcheck(&com[1], &use[0])) {
			break;
		}
	}

	while (1) {
		use[1].num = rand() % 13 + 1;
		use[1].pat = rand() % 4;
		if (cardcheck(&com[0], &use[1]) && cardcheck(&com[1], &use[1]) && cardcheck(&use[0], &use[1])) {
			break;
		}
	}

}

bool blackjack::cardcheck(struct card* card1, struct card* card2) {
	if (card1->num == card2->num && card1->pat == card2->pat) return 0;
	return 1;
}

char blackjack::readNum(int x) {
	if (x == 1) {
		return  'A';
	}
	else if (x == 10) {
		return '%';
	}
	else if (x < 10) {
		return x + 48;
	}
	else if (x == 11) {
		return 'J';
	}
	else if (x == 12) {
		return 'Q';
	}
	else if (x == 13) {
		return 'K';
	}
}

char blackjack::readPat(int x) {
	if (x == 0) {
		return 'S';
	}
	else if (x == 1) {
		return 'D';
	}
	else if (x == 2) {
		return 'H';
	}
	else if (x == 3) {
		return 'C';
	}
}

//char* blackjack::readPat(int x) {
//	char s[4] = "♠";
//	char d[4] = "◆";
//	char h[4] = "♥";
//	char c[4] = "♣";
//	if (x == 0) {
//		return s;
//	}
//	else if (x == 1) {
//		return d;
//	}
//	else if (x == 2) {
//		return h;
//	}
//	else if (x == 3) {
//		return c;
//	}
//}

void blackjack::comHit() {
	comCount++;
	if (comCount > 8) return;
	int i = comCount - 1;
	while (1) {
		bool flag = 1;
		com[i].num = rand() % 13 + 1;
		com[i].pat = rand() % 4;

		// 중복 검사
		for (int j = 0; j < useCount; j++) {
			if (!cardcheck(&com[i], &use[j])) flag = 0;
		}

		for (int j = 0; j < i; j++) {
			if (!cardcheck(&com[i], &com[j])) flag = 0;
		}

		// 탈출
		if (flag) {
			break;
		}
	}

	this->table(1, 1);
}
void blackjack::useHit() {
	useCount++;
	if (useCount > 8) return;
	int i = useCount - 1;
	while (1) {
		bool flag = 1;
		use[i].num = rand() % 13 + 1;
		use[i].pat = rand() % 4;

		// 중복 검사
		for (int j = 0; j < i; j++) {
			if (!cardcheck(&use[i], &use[j])) flag = 0;
		}

		for (int j = 0; j < comCount; j++) {
			if (!cardcheck(&use[i], &com[j])) flag = 0;
		}

		// 탈출
		if (flag) {
			break;
		}
	}
	this->sum();
	Sleep(1000);
	system("cls");  //테이블 정리 -> cmd 초기화
	this->table(1);
	this->bust();

}

void blackjack::bust() {

	if (21 < useSum) {
		std::cout << "\n================================\nBUST!!\n================================\nYOU LOSE\n";
		gameSet = 1;
		Result(bet, 2);
	}
	else gameSet = 0;
}

void blackjack::winer() { // 딜러 검사후 ->  양측 비교
	this->sum();

	if (21 - comSum > 21 - useSum) {
		std::cout << "\n================================\nYOU WIN\n================================\n";
		Result(bet, 1);
	}
	if (21 - comSum < 21 - useSum) {
		std::cout << "\n================================\nYOU LOSE\n================================\n";
		Result(bet, 2);
	}
	if (21 - comSum == 21 - useSum) {
		std::cout << "\n================================\nDRAW\n================================\n";
		Result(bet, 3);
	}
	gameSet = 1;
}
void blackjack::stop() {
	this->table(1, 1);
	bool flag = 0;
	while (1) {
		this->sum();
		if (comSum > 21) {
			std::cout << "\n================================\nBUST~!, YOU WIN\n================================\n";
			Result(bet, 1);
			flag = 1;
			break;
		}
		else if (comSum == 21) {
			std::cout << "\n================================\n   YOU LOSE   \n================================\n";
			Result(bet, 2);
			flag = 1;
			break;
		}
		else if (comSum < 17) {
			Sleep(2000);
			system("cls");  //테이블 정리 -> cmd 초기화
			this->comHit();
		}
		else break;
	}
	if (!flag) {
		this->sum();
		this->winer();
	}
}


void blackjack::sum() {
	comSum = 0;
	int Acount = 0; // a의 개수
	for (int i = 0; i < comCount; i++) {
		if (com[i].num == 1) {
			comSum += 1;
			Acount++;
		}
		else if (com[i].num < 11) {
			comSum += com[i].num;
		}
		else comSum += 10;
	}
	for (int i = 0; i < Acount; i++) {
		if (comSum + 10 <= 21) {
			comSum += 10;
		}
		else break;
	}

	useSum = 0;
	Acount = 0; // a의 개수
	for (int i = 0; i < useCount; i++) {
		if (use[i].num == 1) {
			useSum += 1;
			Acount++;
		}
		else if (use[i].num < 11) {
			useSum += use[i].num;
		}
		else useSum += 10;
	}
	for (int i = 0; i < Acount; i++) {
		if (useSum + 10 <= 21) {
			useSum += 10;
		}
		else break;
	}
}
