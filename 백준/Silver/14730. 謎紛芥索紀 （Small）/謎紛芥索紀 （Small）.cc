#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int result = 0;

	for (int i = 0; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		result += n1 * n2;
	}

	cout << result;

	return 0;
}



