#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
void DFS(vector<int>& v, vector<int>& result, int M, int idx);

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> v;
	unordered_map<int, int> um;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (um[num] != 1) {
			um[num] = 1;
			v.push_back(num);
		}
	}

	sort(v.begin(), v.end());

	vector<int> result;
	DFS(v, result, M, 0);

	return 0;
}

void DFS(vector<int>& v, vector<int>& result, int M, int idx)
{
	if (result.size() == M) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << '\n';

		return;
	}

	for (int i = idx; i < v.size(); i++) {
		result.push_back(v[i]);
		DFS(v, result, M, i);
		result.pop_back();
	}
}