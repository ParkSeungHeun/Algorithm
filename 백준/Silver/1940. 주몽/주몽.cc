#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int arr[15001];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int count = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if ((arr[i] + arr[j]) == m) {
				count++;
			}
		}
	}

	cout << count;

	return 0;
}
