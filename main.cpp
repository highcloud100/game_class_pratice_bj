//#include <iostream>
//#include <ctime>
//#include <windows.h>
//
//struct card
//{
//	int pat; // ����
//	int num; // ����
//	
//};
//
//class blackjack {
//
//	bool gameSet;
//	int comCount; // ���� ī�� ����
//	int useCount; // ������ ī�� ����
//	int comSum;   // ��
//	int useSum;	  // ��
//	struct card* com; // ������ ī��
//	struct card* use; // ������ ī��
//
//public:
//	blackjack() : comCount(2), useCount(2),comSum(0), useSum(0),gameSet(0) {
//		std::cout << "BLACK JACK\n\n";
//		com = new struct card[8]; // ī�� �Ҵ�
//		use = new struct card[8]; // ī�� �Ҵ�
//	}
//	//=========================================================== �÷���
//	void bust();   // 21 �ʰ�
//	void comHit(); // ���� hit
//	void useHit(); // ���� hit
//	void winer();  // ���� �̰���� �Ǵ�
//	void stop();    // ���� hit, �������
//	void sum();    // ī�� ���� ��
//	
//	//=========================================================== ��ī����
//	void table(); //�ʱ� ���̺�
//	void table(int x); // ���� hit table
//	void table(int x, int y); // ���� hit table
//	bool cardcheck(struct card* card1, struct card* card2);
//	void shuffle();
//	char readNum(int x); // ������ ī�� ������� �ؼ�
//	char readPat(int x); 
//
//	//===========================================================���� ��
//	bool getSet() {
//		return gameSet;
//	}
//
//	~blackjack() {
//		system("cls");  //���̺� ���� -> cmd �ʱ�ȭ
//		delete[] com;
//		delete[] use;
//	}
//};
//
//void blackjack::table() {
//	// ���� ���
//	int size = 1;
//	printf("\n\n");
//	for (int i = 0; i < size; i++) {
//		printf("�� %c  �� ", readPat(com[i].pat));
//	}
//	printf("\n");
//
//	for (int i = 0; i < size; i++) {
//		printf("��    �� ");
//	}
//	printf("\n");
//
//	for (int i = 0; i < size; i++) {
//		printf("��   %c�� ", readNum(com[i].num));
//	}
//	printf("\n");
//	//============================
//	printf("\n"); 
//	printf("\n");
//	//============================
//	//���� ���
//	size = useCount;
//	for (int i = 0; i < size; i++) {
//		printf("�� %c  �� ", readPat(use[i].pat));
//	}
//	printf("\n");
//
//	for (int i = 0; i < size; i++) {
//		printf("��    �� ");
//	}
//	printf("\n");
//
//	for (int i = 0; i < size; i++) {
//		printf("��   %c�� ", readNum(use[i].num));
//	}
//	printf("\n");
//
//	// ���� �Ǵ�
//	this->sum();
//	if (21 == useSum) {
//		std::cout << "\n================================\nBLACK JACK!!\n================================\nYOU WIN\n";
//		gameSet = 1;
//	}
//
//}
//
//void blackjack::table(int x) {
//	// ���� ���
//	int size = 1;
//	printf("\n\n");
//	for (int i = 0; i < size; i++) {
//		printf("�� %c  �� ", readPat(com[i].pat));
//	}
//	printf("\n");
//
//	for (int i = 0; i < size; i++) {
//		printf("��    �� ");
//	}
//	printf("\n");
//
//	for (int i = 0; i < size; i++) {
//		printf("��   %c�� ", readNum(com[i].num));
//	}
//	printf("\n");
//	//============================
//	printf("\n");
//	printf("\n");
//	//============================
//	//���� ���
//	size = useCount;
//	for (int i = 0; i < size; i++) {
//		printf("�� %c  �� ", readPat(use[i].pat));
//	}
//	printf("\n");
//
//	for (int i = 0; i < size; i++) {
//		printf("��    �� ");
//	}
//	printf("\n");
//
//	for (int i = 0; i < size; i++) {
//		printf("��   %c�� ", readNum(use[i].num));
//	}
//	printf("\n");
//
//}
//
//void blackjack::table(int x, int y) {
//	// ���� ���
//	int size = comCount;
//	printf("\n\n");
//	for (int i = 0; i < size; i++) {
//		printf("�� %c  �� ", readPat(com[i].pat));
//	}
//	printf("\n");
//
//	for (int i = 0; i < size; i++) {
//		printf("��    �� ");
//	}
//	printf("\n");
//
//	for (int i = 0; i < size; i++) {
//		printf("��   %c�� ", readNum(com[i].num));
//	}
//	printf("\n");
//	//============================
//	printf("\n");
//	printf("\n");
//	//============================
//	//���� ���
//	size = useCount;
//	for (int i = 0; i < size; i++) {
//		printf("�� %c  �� ", readPat(use[i].pat));
//	}
//	printf("\n");
//
//	for (int i = 0; i < size; i++) {
//		printf("��    �� ");
//	}
//	printf("\n");
//
//	for (int i = 0; i < size; i++) {
//		printf("��   %c�� ", readNum(use[i].num));
//	}
//	printf("\n");
//
//}
//
//void blackjack::shuffle() { // �ʱ� 2�徿 ����
//	
//
//	/*for (int i = 0; i < comCount; i++) {
//		while (1) {
//			bool flag = 0;
//			com[i].num = rand() % 13 + 1;
//			com[i].pat = rand() % 4;
//			if (i == 0) {
//				comCount++;
//				break;
//			}
//			for (int j = 0; j < i; j++) {
//				if (cardcheck(&com[i], &com[j])) flag = 1;
//			}
//
//			if (flag) {
//				comCount++;
//				break;
//			}
//		}
//	}*/
//	com[0].num = rand() % 13 + 1;
//	com[0].pat = rand() % 4;
//	
//	while (1) {
//		com[1].num = rand() % 13 + 1;
//		com[1].pat = rand() % 4;
//		if (cardcheck(&com[0], &com[1])) {
//			break;
//		}
//	}
//	
//	while (1) {
//		use[0].num = rand() % 13 + 1;
//		use[0].pat = rand() % 4;
//
//		if (cardcheck(&com[0], &use[0]) && cardcheck(&com[1], &use[0])) {
//			break;
//		}
//	}
//	
//	while (1) {
//		use[1].num = rand() % 13 + 1;
//		use[1].pat = rand() % 4;
//		if (cardcheck(&com[0], &use[1]) && cardcheck(&com[1], &use[1]) && cardcheck(&use[0], &use[1])) {
//			break;
//		}
//	}
//	
//}
//
//bool blackjack::cardcheck(struct card* card1, struct card* card2) {
//	if (card1->num == card2->num && card1->pat == card2->pat) return 0;
//	return 1;
//}
//
//char blackjack::readNum(int x) {
//	if (x == 1) {
//		return  'A';
//	}
//	else if (x == 10) {
//		return '%';
//	}
//	else if (x < 10) {
//		return x + 48;
//	}
//	else if (x == 11) {
//		return 'J';
//	}
//	else if (x == 12) {
//		return 'Q';
//	}
//	else if (x == 13) {
//		return 'K';
//	}
//}
//
//char blackjack::readPat(int x) {
//	if (x == 0) {
//		return 's';
//	}
//	else if (x == 1) {
//		return 'd';
//	}
//	else if (x == 2) {
//		return 'h';
//	}
//	else if (x == 3) {
//		return 'c';
//	}
//}
//
//void blackjack::comHit() {
//	comCount++;
//	if (comCount > 8) return;
//	int i = comCount - 1;
//	while (1) {
//		bool flag = 1;
//		com[i].num = rand() % 13 + 1;
//		com[i].pat = rand() % 4;
//
//		// �ߺ� �˻�
//		for (int j = 0; j < useCount; j++) {
//			if (!cardcheck(&com[i], &use[j])) flag = 0;
//		}
//
//		for (int j = 0; j < i; j++) {
//			if (!cardcheck(&com[i], &com[j])) flag = 0;
//		}
//
//		// Ż��
//		if (flag) {
//			break;
//		}
//	}
//	
//	this->table(1,1);
//}
//void blackjack::useHit() {
//	useCount++;
//	if (useCount > 8) return;
//	int i = useCount - 1;
//	while (1) {
//		bool flag = 1;
//		use[i].num = rand() % 13 + 1;
//		use[i].pat = rand() % 4;
//
//		// �ߺ� �˻�
//		for (int j = 0; j < i; j++) {
//			if (!cardcheck(&use[i], &use[j])) flag = 0;
//		}
//
//		for (int j = 0; j < comCount; j++) {
//			if (!cardcheck(&use[i], &com[j])) flag = 0;
//		}
//
//		// Ż��
//		if (flag) {
//			break;
//		}
//	}
//	this->sum();
//	Sleep(1000);
//	system("cls");  //���̺� ���� -> cmd �ʱ�ȭ
//	this->table(1);
//	this->bust();
//	
//}
//
//void blackjack::bust() {
//	
//	if (21 < useSum) {
//		std::cout << "\n================================\nBUST!!\n================================\nYOU LOSE\n";
//		gameSet = 1;
//	}
//	else gameSet = 0;
//}
//
//void blackjack::winer() { // ���� �˻��� ->  ���� ��
//	this->sum();
//
//	if (21 - comSum > 21 - useSum) {
//		std::cout << "\n================================\nYOU WIN\n================================\n";
//	}
//	if (21 - comSum < 21 - useSum) {
//		std::cout << "\n================================\nYOU LOSE\n================================\n";
//	}
//	if (21 - comSum == 21 - useSum) {
//		std::cout << "\n================================\nDRAW\n================================\n";
//	}
//	gameSet = 1;
//}
//void blackjack::stop() {
//	this->table(1, 1);
//	bool flag = 0;
//	while (1) {
//		this->sum();
//		if (comSum > 21) {
//			std::cout << "\n================================\nBUST~!, YOU WIN\n================================\n";
//			flag = 1;
//			break;
//		}
//		else if (comSum == 21){
//			std::cout << "\n================================\n   YOU LOSE   \n================================\n";
//			flag = 1;
//			break;
//		}
//		else if (comSum < 17) {
//			Sleep(2000);
//			system("cls");  //���̺� ���� -> cmd �ʱ�ȭ
//			this->comHit();
//		}
//		else break;
//	}
//	if (!flag) {
//		this->sum();
//		this->winer();
//	}
//}
//
//
//void blackjack::sum() {
//	comSum = 0;
//	int Acount=0; // a�� ����
//	for (int i = 0; i < comCount; i++) {
//		if (com[i].num == 1) {
//			comSum += 1;
//			Acount++;
//		}
//		else if (com[i].num < 11) {
//			comSum += com[i].num;
//		}
//		else comSum += 10;
//	}
//	for (int i = 0; i < Acount; i++) {
//		if (comSum + 10 <= 21) {
//			comSum += 10;
//		}
//		else break;
//	}
//
//	useSum = 0;
//	Acount = 0; // a�� ����
//	for (int i = 0; i < useCount; i++) {
//		if (use[i].num == 1) {
//			useSum += 1;
//			Acount++;
//		}
//		else if (use[i].num < 11) {
//			useSum += use[i].num;
//		}
//		else useSum += 10;
//	}
//	for (int i = 0; i < Acount; i++) {
//		if (useSum + 10 <= 21) {
//			useSum += 10;
//		}
//		else break;
//	}
//}
//
//int main() {
//	srand(time(0));
//	int x = 1 ; //���� Ƚ��
//
//	int coin = 100;
//
//	while (1) {
//		blackjack game;
//		std::cout << "GAME:" << x<<std::endl;
//		x++;
//
//
//		game.shuffle();
//		game.table();
//
//		
//
//		int choice;
//		while (1) {
//			bool flag = 0;
//			if (game.getSet()) {
//				break;
//			}
//			std::cout << "\n��������������������������������������������������������";
//			std::cout << "\n1).HIT\n2).STAY\n";
//			std::cout << "��������������������������������������������������������\n";
//			std::cout << "CHOICE: ";
//			std::cin >> choice;
//			
//			switch (choice) {
//			case 1:
//				game.useHit();
//				if (game.getSet()) {
//					flag = 1;
//				}
//				break;
//			case 2:
//				system("cls");
//				game.stop();
//				flag = 1;
//			}
//			if (flag) break;
//		}
//
//		char r;
//		std::cout << "CONTINUE?(y/n):";
//		std::cin >> r;
//		if (r == 'n') {
//			return 0;
//		}
//	}
//}


#include "BlackJack.h" //����� ���� �������



void title() {
	system("mode con cols=100 lines=25 | title BLACK JACK");
	printf("\n\n\n\n");
	printf("\t=========================================================================\n");
	printf("\t######  #          #     #####  #    #          #    #     #####  #    # \n");
	printf("\t#     # #         # #   #     # #   #           #   # #   #     # #   #  \n");
	printf("\t#     # #        #   #  #       #  #            #  #   #  #       #  #  \n");
	printf("\t######  #       #     # #       ###             # #     # #       ###  \n");
	printf("\t#     # #       ####### #       #  #      #     # ####### #       #  #  \n");
	printf("\t#     # #       #     # #     # #   #     #     # #     # #     # #   # \n");
	printf("\t######  ####### #     #  #####  #    #     #####  #     #  #####  #    # \n");
	printf("\t=========================================================================\n\n\n");
	Sleep(1500);
}

void dealer() {
	system("cls");
	printf("\tWWWWWWWWWWWWWWWWWWWWWXKOOkkO0XWWWWWWWWWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWWWWWNK00l,.......,cxXWWWWWWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWWWWXd',c, ..........,kWWWWWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWWWNo..'l' ...........,0WWWWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWWWK;..:kkddolcc;'....'xWWWWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWWWK:.:0WWWWWWWWNKkdl;;xNWWWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWW0kdckWXNWWWWWWNWNXW0lxk0WWWWWWWWWWWWW\n"); 
	printf("\tWWWWWWWWWWWWWxkKx0KlkWWWWWWWWklK0xKkxNWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWWKkxoOXOKWN0OO0NWKONOoxOXWWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWWWNNkxXWWWNKO0KNWWWXxkNNWWWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWWWWWN0kOXWWWWWWWNX0x0NWWWWWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWWWWWWNOloOOOOOOOkolONWWWWWWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWWWNKkl;::lkkxdkkl::,ckKNWWWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWWNOxO:,c..cc.'cc..c,:OxOWWWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWWNxOX:.:;,:lddl:,;;.:XOxNWWWWWWWWWWWWW\n");
	printf("\tWWWWWWWWWWWWWWOkOo::cc:codc:cc::oOkONWWWWWWWWWWWWW\n");
	printf("\t==================================================\n");

}

int main() {

	title();
	dealer();
	srand(time(0));
	int x = 1; //���� Ƚ��
	int money;
	std::cout << " ������ �󸶳� �����Խ��ϱ�?(������ 10�����θ� ����մϴ�)\n ";
	std::cin >> money;
	if (money % 10 != 0 || money == 0) {
		return 0;
	}
	std::cout << " ������ ���� ���κ��� ���� �ϰų� ������ 0�� �Ǹ� �����մϴ�.\n ""%""�� 10�� �̾߱� �մϴ�.";
	Sleep(5000);

	//blackjack::allCoin = money;
	blackjack::setallCoin(money);
	system("mode con cols=80 lines=20 | title BLACK JACK");
	while (1) {
		blackjack game;

		std::cout << "GAME:" << x << std::endl;
		x++;
		std::cout << "COIN:" << game.getallCoin() << std::endl;

		int bet;
		std::cout << "BET: ";
		std::cin >> bet;
		game.betCoin(bet);

		game.shuffle();
		game.table();



		int choice;
		while (1) {
			bool flag = 0;
			if (game.getSet()) {
				break;
			}
			std::cout << "\n��������������������������������������������������������";
			std::cout << "\n1).HIT\n2).STAY\n";
			std::cout << "��������������������������������������������������������\n";
			std::cout << "CHOICE: ";
			std::cin >> choice;

			switch (choice) {
			case 1:
				game.useHit();
				if (game.getSet()) {
					flag = 1;
				}
				break;
			case 2:
				system("cls");
				game.stop();
				flag = 1;
			}
			if (flag) break;
		}

		if (game.getallCoin() <= 0) {
			Sleep(4000);
			std::cout << "�� ������ ����\n";
			return 0;
		}

		
		char r;
		std::cout << "COIN: " << game.getallCoin() << " BET: " << game.getbet() << std::endl;
		std::string a;
		
		std::cout << "\nPress Enter Anykey\n";
		std::cin >> a;
		

		system("mode con cols=100 lines=20 | title BLACK JACK");
		dealer();
		std::cout << "\nCONTINUE?(y/n):";
		std::cin >> r;
		if (r == 'n') {
			return 0;
		}
	}
}

