#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct Mer {
	int v;
	int c;
};

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N, K;
		cin >> N >> K;
		
		Mer mer[101];
		for (int i = 1; i <= N; i++) {
			int v, c;
			cin >> v >> c;

			mer[i] = { v, c };
		}

		int DP[101][1001] = { 0, };

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= K; j++) {
				if (mer[i].v > j) {
					DP[i][j] = DP[i - 1][j];
				}
				else {
					DP[i][j] = max(DP[i - 1][j - mer[i].v] + mer[i].c, DP[i - 1][j]);
				}
			}
		}

		cout << "#" << test_case << " " << DP[N][K] << '\n';
	}
	
	return 0;
}
