#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int Find(int arr[], int x);
void Union(int arr[], int x, int y);

int main() {
	
	int N, M;
	cin >> N >> M;

	int T;
	cin >> T;

	vector<int> team[51];
	
	int arr[51];

	for (int i = 0; i <= N; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;

		arr[num] = 0;
	}

	int result = M;
	
	for (int i = 0; i < M; i++) {
		// 파티에 오는 사람 수,
		int num;
		cin >> num;

		int f1;
		cin >> f1;
		team[i].push_back(f1);

		for (int j = 1; j < num; j++) {
			int f2;
			cin >> f2;
			team[i].push_back(f2);
			Union(arr, f1, f2);
		}
	}

	// 그 후 팀의 개수만큼 반복문돌려서 Find 하기
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < team[i].size(); j++) {
			if (Find(arr, arr[team[i][j]]) == 0) {
				result--;
				break;
			}
		}
	}

	cout << result;
	return 0;
}

int Find(int arr[], int x)
{
	if (arr[x] != x) {
		return arr[x] = Find(arr, arr[x]);
	}
	else {
		return arr[x];
	}
}

void Union(int arr[], int x, int y)
{
	int f1 = Find(arr, x);
	int f2 = Find(arr, y);

	if (f1 != f2) {
		if (f1 < f2) {
			arr[f2] = arr[f1];
		}
		else {
			arr[f1] = arr[f2];
		}
	}
}