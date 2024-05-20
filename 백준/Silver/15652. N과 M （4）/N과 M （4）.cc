#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void DFS(int N, int M, int idx, int level, vector<int>& v);

int main()
{
	vector<int> v;

	int N, M;
	cin >> N >> M;

	DFS(N, M, 1, 0, v);

	return 0;
}

void DFS(int N, int M, int idx, int level, vector<int>& v)
{
	if (level == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i <= N; i++) {
		v.push_back(i);
		DFS(N, M, i, level + 1, v);
		v.pop_back();
	}
}

