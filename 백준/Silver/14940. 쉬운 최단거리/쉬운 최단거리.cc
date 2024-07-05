#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int y;
	int x;
};

void Solution(int map[][1001], int visited[][1001], int N, int M, Node start);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int map[1001][1001] = { 0, };
	
	Node start = { 0, 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				start = { i, j };
			}
		}
	}

	int visited[1001][1001] = { 0, };

	Solution(map, visited, N, M, start);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cout << 0 << " ";
			}
			else {
				cout << visited[i][j] - 1 << " ";
			}
			
		}
		cout << '\n';
	}
	
	return 0;
}

void Solution(int map[][1001], int visited[][1001], int N, int M, Node start)
{
	int direction_x[4] = { 0, 0, -1, 1 };
	int direction_y[4] = { 1, -1, 0, 0 };

	queue<Node> q;
	q.push(start);
	visited[start.y][start.x] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + direction_y[i];
			int nx = now.x + direction_x[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

			if (map[ny][nx] == 0) continue;

			if (visited[ny][nx] > 0) continue;

			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny, nx });
		}
	}
	
}
