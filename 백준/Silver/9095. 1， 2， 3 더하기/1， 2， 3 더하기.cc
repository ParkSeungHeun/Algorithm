#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void Solution(int N, int count, int* result);

int main() {
	
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N;
		cin >> N;

		int result = 0;
		
		Solution(N, 0, &result);

		cout << result << '\n';
	}
	return 0;
}

void Solution(int N, int count, int* result)
{
	if (count > N) {
		return;
	}
	else {
		if (count == N) {
			(*result)++;
		}
	}

	Solution(N, count + 1, result);
	Solution(N, count + 2, result);
	Solution(N, count + 3, result);
}
