#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int map[100005] = { 0, };
	for (int i = 0; i < 100005; i++) {
		map[i] = 21e8;
	}

	map[N] = 0;
	queue<int> q;
	q.push(N);
	
	int time = 1;
	while (!q.empty()) {

		int T;
		T = q.size();

		for (int i = 0; i < T; i++) {
			int num = q.front();
			q.pop();

			int next1 = num + 1;
			int next2 = num - 1;
			int next3 = num * 2;

			if (next1 >= 0 && next1 <= 100000) {
				if (map[next1] > time) {
					q.push(next1);
					map[next1] = time;
				}
			}

			if (next2 >= 0 && next2 <= 100000) {
				if (map[next2] > time) {
					q.push(next2);
					map[next2] = time;
				}
			}

			if (next3 >= 0 && next3 <= 100000) {
				if (map[next3] > time) {
					q.push(next3);
					map[next3] = time;
				}
			}
		}
		
		time++;
	}

	cout << map[K];
	return 0;
}
