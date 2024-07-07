#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long Solution(int K, int mod);

// 분할정복
// 1번 사탕 A, 2번 사탕 B, 사탕의 합 A + B = C
// n번째 단계에서 A개가 더 적으면 2A가 되고, 만약 A가 더 크면 A에서 (C - A) 만큼 빼게 되어 2A - C가 된다.
// (2A - C) % C = 2A % C, 이는 2A % C와 동일
// 즉, (2A - C) % C와 (2A) % C는 같다~~~
// 두 번 반복하면 (2 ^ 2A) % C => (2^K*A) % C
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int A, B, K;
		cin >> A >> B >> K;

		long long result = ((long long)Solution(K, A + B) * (long long)A) % (A + B);
		if (result > (A + B) / 2) {
			cout << "#" << test_case << " " << (A + B) - result << '\n';
		}
		else {
			cout << "#" << test_case << " " << result << '\n';
		}		
	}
	return 0;
}

long long Solution(int K, int mod)
{
	long long res = 1;
	long long num = 2;

	while (K > 0) {
		if (K % 2 == 1) {
			res = (res * num) % mod;
		}
		num = (num * num) % mod;
		K /= 2;
	}

	return res;
}