#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void DFS(vector<int>& v, bool visited[], int N, int M, int idx, int level, vector<int>& result);

int main()
{
	vector<int> v;

	int N, M;
	cin >> N >> M;

	vector<int> result;

	for (int i = 0; i < N; i++) {
		int num = 0;
		cin >> num;

		v.push_back(num);
	}

	sort(v.begin(), v.end());
	bool visited[8] = { false };

	DFS(v, visited, N, M, 0, 0, result);

	return 0;
}

void DFS(vector<int>& v, bool visited[], int N, int M, int idx, int level, vector<int>& result)
{
	if (level == M) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == true) continue;

		result.push_back(v[i]);
		visited[i] = true;
		DFS(v, visited, N, M, i, level + 1, result);
		visited[i] = false;
		result.pop_back();
	}
}

