#include <iostream>
#include <vector>

using namespace std;

struct Bag {
	int weight;
	int value;
};

int main()
{
	int N, K;
	cin >> N >> K;

	vector<Bag> bag;
	for (int i = 0; i < N; i++) {
		int weight, value;
		cin >> weight >> value;

		bag.push_back({ weight, value });
	}

	// 0번 물건부터 시작~~
	// DP의 y축 : 물건의 무게
	// DP의 x축 : 물건 번호
	// DP의 값 : 최대 가치
	int DP[100001][101] = { 0, };

	// i : 물건 번호
	for (int i = 0; i < N; i++) {
		// j : 현재 가방의 크기
		for (int j = 1; j <= K; j++) {
			// 현재 고른 물건의 무게와 가치
			Bag now = bag[i];
			// 현재 가방에 넣을 수 없으면 옆거
			if (now.weight > j) {
				DP[j][i] = DP[j][i - 1];
			}
			else {
				DP[j][i] = max(DP[j][i - 1], DP[j - now.weight][i - 1] + now.value);
			}
		}
	}

	cout << DP[K][N - 1];
	return 0;
}