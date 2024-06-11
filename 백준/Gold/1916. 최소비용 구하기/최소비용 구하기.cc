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

void Solution(vector<Node> map[], int arr[], int start, int end);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<Node> map[1001];

	for (int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;

		map[u].push_back({ v, c });
	}

	int start, end;
	cin >> start >> end;

	int arr[1001] = { 0 };
	for (int i = 1; i <= N; i++) {
		arr[i] = 21e8;
	}

	Solution(map, arr, start, end);
	cout << arr[end];
	return 0;
}

void Solution(vector<Node> map[], int arr[], int start, int end)
{
	priority_queue<Node> pq;
	arr[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (now.cost > arr[end]) continue;

		for (int i = 0; i < map[now.point].size(); i++) {
			Node next = map[now.point][i];
			int nextcost = arr[now.point] + next.cost;

			if (nextcost >= arr[next.point]) continue;

			arr[next.point] = nextcost;
			pq.push({ next.point, nextcost });
		}
	}
}



