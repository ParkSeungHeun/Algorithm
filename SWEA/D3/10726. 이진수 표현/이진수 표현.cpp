#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N, num;
		cin >> N >> num;
		
		bool flag = true;

		for (int i = 0; i < N; i++) {
			int tmp = num & (0b1);
			if (tmp != 1) {
				flag = false;
				break;
			}
			num = (num >> 1);
		}

		if (flag) {
			cout << "#" << test_case << " " << "ON" << '\n';
		}
		else {
			cout << "#" << test_case << " " << "OFF" << '\n';
		}

	}
	return 0;
}
