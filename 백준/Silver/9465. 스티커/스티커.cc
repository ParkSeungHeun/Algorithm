#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N;
		cin >> N;

		int map[2][100000] = { 0, };

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		// DP
		int DP[2][100001] = { 0, };
		DP[0][1] = map[0][0];
		DP[1][1] = map[1][0];

		for (int i = 2; i <= N; i++) {
			DP[0][i] = max(DP[1][i - 1], DP[1][i - 2]) + map[0][i - 1];
			DP[1][i] = max(DP[0][i - 1], DP[0][i - 2]) + map[1][i - 1];
		}

		cout << max(DP[0][N], DP[1][N]) << '\n';
	}
	return 0;
}