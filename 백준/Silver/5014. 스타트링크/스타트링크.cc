#include <iostream>
#include <queue>

using namespace std;

void Solution(int arr[], int F, int S, int U, int D);

int main() 
{
	// F : 고층 건물 S : 강호 위치 G : 목적지
	int F, S, G, U, D;

	cin >> F >> S >> G >> U >> D;

	int arr[1000001];

	for (int i = 0; i <= F; i++) {
		arr[i] = 21e8;
	}

	Solution(arr, F, S, U, D);
	
	if (arr[G] == 21e8) {
		cout << "use the stairs";
	}
	else {
		cout << arr[G];
	}

	return 0;
}

void Solution(int arr[], int F, int S, int U, int D)
{
	queue<int> q;
	q.push(S);
	arr[S] = 0;

	int count = 1;

	while (!q.empty())
	{
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int n;
			n = q.front();
			q.pop();

			if (n + U <= F && arr[n + U] > count) {
				arr[n + U] = count;
				q.push(n + U);
			}

			if (n - D >= 1 && arr[n - D] > count) {
				arr[n - D] = count;
				q.push(n - D);
			}
		}

		count++;
	}

}