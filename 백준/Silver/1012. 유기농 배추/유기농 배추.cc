#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void Solution(int map[][50], int N, int M, int y, int x);

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N, M, K;
		cin >> M >> N >> K;

		int map[50][50] = { 0, };
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;

			map[y][x] = 1;
		}

		int count = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					// DFS
					Solution(map, N, M, i, j);
					count++;
				}
			}
		}

		cout << count << '\n';
	}
	return 0;
}

void Solution(int map[][50], int N, int M, int y, int x)
{
	int direction_x[4] = { 0, 0, -1, 1 };
	int direction_y[4] = { -1, 1, 0, 0 };

	map[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + direction_y[i];
		int nx = x + direction_x[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

		if (map[ny][nx] == 0) continue;

		Solution(map, N, M, ny, nx);
	}
}
