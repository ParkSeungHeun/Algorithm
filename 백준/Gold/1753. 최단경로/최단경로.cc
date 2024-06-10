#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int point;
	int cost;

	bool operator<(Node right) const {
		return cost > right.cost;
	}
};

void Solution(vector<Node> map[], int arr[], int N, int start);

int main()
{
	// 다익스트라
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, start;
	cin >> N >> M >> start;

	vector<Node> map[20001];
	
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		map[u].push_back({ v, w });
	}

	// rr
	int arr[20001] = { 0 };
	for (int i = 1; i < N + 1; i++) {
		arr[i] = 21e8;
	}

	Solution(map, arr, N, start);

	for (int i = 1; i < N + 1; i++) {
		if (arr[i] == 21e8) {
			cout << "INF" << '\n';
		}
		else {
			cout << arr[i] << '\n';
		}
	}

	return 0;
}

void Solution(vector<Node> map[], int arr[], int N, int start)
{
	priority_queue<Node> pq;
	arr[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		for (int i = 0; i < map[now.point].size(); i++) {
			Node next = map[now.point][i];
			int nextcost = now.cost + next.cost;

			if (nextcost >= arr[next.point]) continue;

			pq.push({ next.point, nextcost });
			arr[next.point] = nextcost;
		}
	}
}



