#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

//백준 1100번 코드
char chess[8][8];
int main() {
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> chess[i][j];
			if (((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))&&chess[i][j]=='F') {
				sum++;
			}
		}
	}
	cout << sum;
}