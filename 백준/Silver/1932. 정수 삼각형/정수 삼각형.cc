#include <iostream>
#include <math.h>

using namespace std;

int main()
{

	int N;
	cin >> N;

	int arr[500][500] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> arr[i][j];
		}
	}

	// 이 문제는 아래에서 위로 올라가면 서 최대가 되는 값을 누적시키는 DP

	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			arr[i - 1][j] += max(arr[i][j], arr[i][j + 1]);
		}
	}

	cout << arr[0][0] << '\n';
	return 0;
}