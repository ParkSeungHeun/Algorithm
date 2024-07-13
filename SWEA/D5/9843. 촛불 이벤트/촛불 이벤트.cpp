#include <iostream>

using namespace std;

int Solution(long long int N);
long long int Cul(long long int num);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	
	for (int test_case = 1; test_case <= T; test_case++)
	{
		long long int N;
		cin >> N;

		cout << "#" << test_case << " " << Solution(N) << '\n';
	}
	return 0;
}

int Solution(long long int N)
{
	long long int start = 1;
	long long int end = 10000000000LL;
	long long int res = 0;

	while (start <= end) {
		long long int mid = (start + end) / 2;

		if (Cul(mid) == N) {
			return mid;
		}

		if (Cul(mid) > N) {
			end = mid - 1;
		}

		if (Cul(mid) < N) {
			start = mid + 1;
			res = mid;
		}
	}

	if (res != N) {
		return -1;
	}
	else {
		return res;
	}
}

long long int Cul(long long int num)
{
	return (num * (num + 1)) / 2;
}
