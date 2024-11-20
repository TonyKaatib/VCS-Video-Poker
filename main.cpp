#include <iostream>
#include <chrono>
#include <random>
#include <conio.h>
#include <unordered_map>
#include <algorithm>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define S(array) sizeof(array) / sizeof(array[0])

using namespace std;

string charset(int suit) {
	string charsuit;
	switch (suit) {
	case (1):
		charsuit = "H";
		break;
	case (2):
		charsuit = "D";
		break;
	case (3):
		charsuit = "S";
		break;
	case (4):
		charsuit = "C";
		break;
	}
	return charsuit;
}

string cardset(int card) {
	string charcard;
	switch (card) {
	case (1):
		charcard = "A";
		break;
	case (2):
		charcard = "2";
		break;
	case (3):
		charcard = "3";
		break;
	case (4):
		charcard = "4";
		break;
	case (5):
		charcard = "5";
		break;
	case (6):
		charcard = "6";
		break;
	case (7):
		charcard = "7";
		break;
	case (8):
		charcard = "8";
		break;
	case (9):
		charcard = "9";
		break;
	case (10):
		charcard = "10";
		break;
	case (11):
		charcard = "J";
		break;
	case (12):
		charcard = "Q";
		break;
	case (13):
		charcard = "K";
		break;
	}
	return charcard;
}

bool isDukesOrBetter(int array[], int size) {
	unordered_map<int, size_t> count;
	for (int i = 0; i < size; i++) {
		count[array[i]]++;
	}
	for (int i = 10; i < 14; i++) {
		if (count[i] == 2)
			return true;
	}
	return false;
}

bool isTwoPairs(int array[], int size) {
	unordered_map<int, size_t> count;
	for (int i = 0; i < size; i++) {
		count[array[i]]++;
	}
	for (auto n : count) {
		if (count.size() == 3 && n.second != 3)
			return true;
	}
	return false;
}

bool isThreeOfAKind(int array[], int size) {
	unordered_map<int, size_t> count;
	for (int i = 0; i < size; i++) {
		count[array[i]]++;
	}
	for (auto n : count) {
		if (count.size() == 3 && n.second == 3)
			return true;
	}
	return false;
}

bool isFullHouse(int array[], int size) {
	unordered_map<int, size_t> count;
	for (int i = 0; i < size; i++) {
		count[array[i]]++;
	}
	for (auto n : count) {
		if (count.size() == 2 && n.second == 3)
			return true;
	}
	return false;
}

bool isFourOfAKind(int array[], int size) {
	unordered_map<int, size_t> count;
	for (int i = 0; i < size; i++) {
		count[array[i]]++;
	}
	for (auto n : count) {
		if (count.size() == 2 && n.second == 4)
			return true;
	}
	return false;
}

bool isStraight(int array[], int n) {
	unordered_map<int, int> map;
	for (int i = 0; i < n; i++) {
		map[array[i]]++;
	}
	if (map.size() == 1)
		return true;
	else return false;
}

bool isAceStraight(int array[], int n) {
	unordered_map<int, int> map;
	for (int i = 1; i < n; i++) {
		map[array[i]]++;
	}
	if (map.size() == 1 && array[0] == 5 && array[4] == 13)
		return true;
	else return false;
}

bool isFlush(int array[], int n) {
	unordered_map<int, int> map;
	for (int i = 0; i < n; i++) {
		map[array[i]]++;
	}
	if (map.size() == 1)
		return true;
	else return false;
}

bool isStraightFlush(int rank[], int suite[], int size) {
	if (isFlush(suite, size) && isStraight(rank, size))
		return true;
	else return false;
}

bool isRoyalFlush(int rank[], int suite[], int size) {
	if (isFlush(suite, size) && isAceStraight(rank, size))
		return true;
	else return false;
}

char* evaluatepokerhand(int cardrank[5], int cardsuite[5], int size) {
	string result[9] = { "Nothing", "Jacks or Better!", "Two Pairs!", "Straight!", "Flush!", "Full House!", "Four of a Kind!", "Straight Flush!", "Royal Flush" };

	int copyArray[5];
	std::copy(cardrank, cardrank + size, copyArray);
	sort(copyArray, copyArray + size);
	int sumArray[5] = { 4, 3, 2, 1, 0 };
	int straightArray[5];
	for (int i = 0; i < 5; i++) {
		straightArray[i] = copyArray[i] + sumArray[i];
	}
	cout << "Dukes or Better? ";
	if (isDukesOrBetter(cardrank, 5))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << "Two Pairs? ";
	if (isTwoPairs(cardrank, 5))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << "Three of a Kind? ";
	if (isThreeOfAKind(cardrank, 5))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << "Full House? ";
	if (isFullHouse(cardrank, 5))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << "Flush? ";
	if (isFlush(cardsuite, 5))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << "Straight? ";
	if (isStraight(straightArray, 5))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << "Ace Straight? ";
	if (isAceStraight(straightArray, 5))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << "Straight Flush? ";
	if (isStraightFlush(straightArray, cardsuite, 5))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << "Royal Flush? ";
	if (isRoyalFlush(straightArray, cardsuite, 5))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

char* handresult(int* hand[5]) {
	for (int i = 0; i < 5; i++) {
		cout << cardset(hand[i][0]) << charset(hand[i][1]) << " ";
	}
	return 0;
}

int main(int argc, char** argv) {
	std::random_device rn;
	std::mt19937 genn(rn());
	std::uniform_int_distribution<> distn(1, 13);

	std::random_device rs;
	std::mt19937 gens(rs());
	std::uniform_int_distribution<> dists(1, 4);

	int n1 = distn(genn);
	int n2 = distn(genn);
	int n3 = distn(genn);
	int n4 = distn(genn);
	int n5 = distn(genn);

	int s1 = dists(gens);
	int s2 = dists(gens);
	int s3 = dists(gens);
	int s4 = dists(gens);
	int s5 = dists(gens);

	string cs1 = charset(s1);
	string cs2 = charset(s2);
	string cs3 = charset(s3);
	string cs4 = charset(s4);
	string cs5 = charset(s5);

	string cc1 = cardset(n1);
	string cc2 = cardset(n2);
	string cc3 = cardset(n3);
	string cc4 = cardset(n4);
	string cc5 = cardset(n5);

	int c1[2] = { n1, s1 };
	int c2[2] = { n2, s2 };
	int c3[2] = { n3, s3 };
	int c4[2] = { n4, s4 };
	int c5[2] = { n5, s5 };

	int card[5] = { n1, n2, n3, n4, n5 };
	int suite[5] = { s1, s2, s3, s4, s5 };

	int* hand[5] = { c1, c2, c3, c4, c5 };

	cout << "Video poker!" << endl;
	handresult(hand);
	cout << endl;
	cout << "\n";
	int size = sizeof(card) / sizeof(card[0]);
	evaluatepokerhand(card, suite, size);
}