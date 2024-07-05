#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int Max(int a, int b);

int main()
{
	int N;
	cin >> N;

	int DP[350] = { 0, };
	int stair[350] = { 0 };

	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}

	DP[1] = stair[1];
	DP[2] = stair[1] + stair[2];
	DP[3] = Max(stair[1] + stair[3], stair[2] + stair[3]);

	for (int i = 4; i <= N; i++) {
		DP[i] = Max(DP[i - 2] + stair[i], DP[i - 3] + stair[i - 1] + stair[i]);
	}

	cout << DP[N];
	
	return 0;
}

int Max(int a, int b)
{
	return a > b ? a : b;
}