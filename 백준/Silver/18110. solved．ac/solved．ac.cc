#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int res = 0;

	// 난이도 의견 개수 입력
	cin >> n;

	// 난이도 의견 개수가 0이면 0을 반환
	if (n == 0)
	{
		cout << res;
		return 0;
	}

	// 난이도 의견 입력
	vector<int> numbers(n);

	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	// 난이도 정렬
	sort(numbers.begin(), numbers.end());

	// 절사평균으로 제외하는 의견 수 계산
	int idx = round(n * 0.15);
	double sum = 0;

	// 절사평균으로 제외하고 난 뒤 의견들 총합 계산
	for (int i = idx; i < n - idx; i++)
		sum += numbers[i];

	// 평균 계산(반올림)
	res = round(sum / (n - idx * 2));

	// 최종 답 반환
	cout << res;

	return 0;
}