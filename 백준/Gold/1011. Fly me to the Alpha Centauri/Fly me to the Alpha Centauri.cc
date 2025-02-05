#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		// 거리가 1일 때 1
		// 거리가 2일 때 11
		// 거리가 3일 때 111
		// 거리가 4일 때 121
		// 거리가 5일 때 1211
		// 거리가 6일 때 1221
		// 거리가 7일 때 12211
		// 거리가 8일 때 12221
		// 거리가 9일 때 12321

		int distance = y - x;
		int s = sqrt(distance);
		int result = 0;

		// 제곱을 지날 때 마다, 제곱 수 중간값을 지날 때 마다 횟수가 1씩 추가됨
		if (pow(s, 2) == distance) {
			result = 2 * s - 1;
		}
		else {
			result = 2 * s;
		}

		// 중간값을 지날 때의 경우
		if (distance > s * (s + 1)) {
			result++;
		}

		printf("%d\n", result);
	}

	
	return 0;
}
