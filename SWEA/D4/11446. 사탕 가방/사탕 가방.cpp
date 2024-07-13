#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	
	for (int test_case = 1; test_case <= T; test_case++)
	{
		// N개의 종류의 사탕, 가방안엔 M개의 사탕이 들어있어야 한다
		// 모든 가방에 들어 있는 사탕 종류의 구성이 같아야 함.
		// -> 모든 
		long long int N, M;
		cin >> N >> M;

		vector <long long int> candy;
		long long int max = -1;

		for (int i = 0; i < N; i++) {
			long long int num = 0;
			cin >> num;

			candy.push_back(num);
			if (num > max) {
				max = num;
			}
		}

		long long int start = 1;
		long long end = max;
		long long ans = 0;

		while (start <= end) {
			long long mid = (start + end) / 2;

			// 가방을 mid 개 만큼 만들 것이라고 결정했다.
			// 각 가방에 최대 몇 개의 사탕을 넣을 수 있는 지
			long long sum = 0LL;
			for (int i = 0; i < N; i++) {
				sum += (candy[i] / mid);
			}

			if (sum < M) {
				end = mid - 1;
			}
			else {
				ans = mid;
				start = mid + 1;
			}
		}
		
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}
