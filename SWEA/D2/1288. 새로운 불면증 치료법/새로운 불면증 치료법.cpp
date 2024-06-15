#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	int total = (1 << 10) - 1;  // 모든 숫자가 등장했을 때의 값

	for (int test_case = 1; test_case <= T; test_case++)
	{
        int N;
        cin >> N;

        int visited = 0;
        int count = 0;
        while (true) {
            string strNum = to_string(N * (++count));  // N*count 값을 문자열로 표현한 것  (예: 5 * 13 = 65 -> "65")

            for (char c : strNum) {
                int num = c - '0';
                visited |= (1 << num);  // 각 숫자에 대해 등장했다는 의미로 bit 를 1로 변경
            }

            if (visited == total)  // 모든 숫자가 등장했다면, 종료
                break;
        }

        cout << "#" << test_case << " " << N * count << endl;
	}
	return 0;
}
