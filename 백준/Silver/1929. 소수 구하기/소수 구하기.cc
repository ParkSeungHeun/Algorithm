#include<cmath>
#include<iostream>

using namespace std;

int arr[1000001];
int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 2; i <= m; i++)
		arr[i] = i;

	for (int i = 2; i <= sqrt(m); i++)		//	2부터 m의 제곱근까지
	{
		if (arr[i] == 0)		//	arr[i]가 0이면 이미 소수가 아닌 것
			continue;
		for (int j = i * i; j <= m; j += i)		//	i*i 전까지는 이미 검사가 되었기 때문에 i*i부터 시작
			arr[j] = 0;
	}

	for (int i = n; i <= m; i++)
	{
		if (arr[i] == 0)
			continue;
		else
			cout << arr[i] << '\n';
	}
	return 0;
}