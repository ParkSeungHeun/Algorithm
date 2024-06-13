#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void Solution(bool DAT[], int* idx, int N);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N;
		cin >> N;

		bool DAT[10] = { false };
		int idx = 1;
		Solution(DAT, &idx, N);
		cout << "#" << test_case << " " << idx * N << '\n';
	}
	return 0;
}

void Solution(bool DAT[], int* idx, int N)
{

	int num = N * (*idx);
	while (num > 0) {
		DAT[num % 10] = true;
		num /= 10;
	}

	bool flag = true;
	for (int i = 0; i < 10; i++) {
		if (!DAT[i]) {
			flag = false;
			break;
		}
	}

	if (!flag) {
		(*idx)++;
		Solution(DAT, idx, N);
	}
}


