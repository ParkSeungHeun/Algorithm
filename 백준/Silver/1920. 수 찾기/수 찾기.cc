#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	unordered_map<int, int> um;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		um[num] = 1;
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		if (um[num] == 1) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	return 0;
}
