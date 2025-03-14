#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
	int start;
	int end;
	int cost;

	bool operator<(Node right) const {
		return cost > right.cost;
	}
};

struct Cost {
	int cost;
	int path;
};

void Solution(vector<Node> map[], int start, int end);

int main() {
	
	int N, M;
	cin >> N >> M;

	vector<Node> map[1001];

	for (int i = 0; i < M; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;

		map[start].push_back({ start, end, cost });
	}

	int start, end;
	cin >> start >> end;

	Solution(map, start, end);

	return 0;
}

// 다익스트라인데, 결과 배열에 경로를 저장하는 
void Solution(vector<Node> map[], int start, int end)
{
	Cost arr[1001];

	for (int i = 0; i <= 1000; i++) {
		arr[i].cost = 21e8;
	}

	priority_queue<Node> pq;
	arr[start].cost = 0;
	arr[start].path = start;

	pq.push({ start, start, 0 });

	while (!pq.empty())
	{
		Node cur = pq.top();
		pq.pop();

		if (arr[cur.start].cost < cur.cost) continue;

		for (int i = 0; i < map[cur.start].size(); i++) {
			// next에 next 좌표 정보와 코스트가 있음
			Node next = map[cur.start][i];
			
			int nextcost = next.cost + arr[cur.start].cost;

			// 값이 nextcost가 더 크면 넘어가기
			if (arr[next.end].cost <= nextcost) continue;

			// 만약 더 값싸면 
			arr[next.end].path = cur.start;
			arr[next.end].cost = nextcost;
			pq.push({ next.end, end, nextcost });
		}
	}

	cout << arr[end].cost << '\n';
	int result_path = end;
	vector<int> result;
	result.push_back(end);

	while (result_path != start) {
		result.push_back(arr[result_path].path);
		result_path = arr[result_path].path;
	}

	cout << result.size() << '\n';
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
}