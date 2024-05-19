#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int y;
	int x;
};

void BFS(char map[][101], int N, int M, int* min);

int main()
{
	int N, M;
	cin >> N >> M;

	char map[101][101];
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	int min = 0;
	// 시작은 0, 0
	BFS(map, N, M, &min);
	cout << min;
	return 0;
}

void BFS(char map[][101], int N, int M, int* min)
{
	int direction_x[4] = { 0, 0, -1, 1 };
	int direction_y[4] = { 1, -1, 0, 0 };

	int arr[101][101] = { 0, };
	queue<Node> q;
	arr[0][0] = 1;
	q.push({0, 0});

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + direction_y[i];
			int nx = now.x + direction_x[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

			if (arr[ny][nx] != 0) continue;

			if (map[ny][nx] == '0') continue;

			q.push({ ny , nx });
			arr[ny][nx] = arr[now.y][now.x] + 1;
		}
	}

	(*min) = arr[N - 1][M - 1];
}

