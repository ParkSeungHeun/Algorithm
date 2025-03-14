#include <iostream>

using namespace std;
void Solution(long long int num, long long int B, int count, int* result);

int main() {
	
	long long int A, B;
	cin >> A >> B;

	int result = 21e8;

	Solution(A, B, 1, &result);

	if (result != 21e8) {
		cout << result;
	}
	else {
		cout << -1;
	}

	return 0;
}

void Solution(long long int num, long long int B, int count, int* result)
{
	if (count >= (*result)) {
		return;
	}

	if (num > B) {
		return;
	}
	else {
		if (num == B) {
			(*result) = count;
			return;
		}
	}

	Solution(num * 10 + 1, B, count + 1, result);
	Solution(num * 2, B, count + 1, result);
}
