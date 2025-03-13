#include <iostream>
#include <queue>

#define MAX 100001

using namespace std;
void Solution(int arr[], int X);

int main() {
	int X, K;
	cin >> X >> K;

	int arr[100001] = { 0, };

	for (int i = 0; i < MAX; i++) {
		arr[i] = 21e8;
	}

	Solution(arr, X);
	cout << arr[K];
}

void Solution(int arr[], int X)
{
	arr[X] = 0;
	queue<int> q;
	q.push(X);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur * 2 <= 100000 && arr[cur] < arr[cur * 2]) {
			arr[cur * 2] = arr[cur];
			q.push(cur * 2);
		}

		if (cur - 1 >= 0 && arr[cur] + 1 < arr[cur - 1]) {
			arr[cur - 1] = arr[cur] + 1;
			q.push(cur - 1);
		}

		if (cur + 1 <= 100000 && arr[cur] + 1 < arr[cur + 1]) {
			arr[cur + 1] = arr[cur] + 1;
			q.push(cur + 1);
		}

	}
}

