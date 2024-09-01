#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void DFS(vector<int> map[], bool visited[], int node[], int num);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	vector<int> map[100001];
	
	for (int i = 0; i < N - 1; i++) {
		int s, e;
		cin >> s >> e;

		// 경로
		map[s].push_back(e);
		map[e].push_back(s);
	}

	bool visited[100001] = { false };
	int node[100001] = { 0, };

	DFS(map, visited, node, 1);
	
	for (int i = 2; i <= N; i++) {
		cout << node[i] << '\n';
	}
	return 0;
}

void DFS(vector<int> map[], bool visited[], int node[], int num)
{
	for (int i = 0; i < map[num].size(); i++) {
		// 방문한 점이면 넘어가기
		if (visited[map[num][i]] == true) continue;

		// 그게 아니면 방문처리하고 부모 표시하고 
		visited[map[num][i]] = true;
		node[map[num][i]] = num;
		DFS(map, visited, node, map[num][i]);
	}
}



