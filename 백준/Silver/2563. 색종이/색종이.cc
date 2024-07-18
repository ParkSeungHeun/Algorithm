#include <stdio.h>

int main()
{
	int arr[100][100] = {0,};
	int a, b, n;
	int cnt = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d %d", &a, &b);
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				arr[a + j][b + k] = 1;
			}
		}
	}

	for (int x = 0; x < 100; x++)
	{
		for (int y = 0; y < 100; y++)
		{
			if (arr[x][y] == 1)
				cnt++;
		}
	}
	printf("%d", cnt);

	return (0);
}