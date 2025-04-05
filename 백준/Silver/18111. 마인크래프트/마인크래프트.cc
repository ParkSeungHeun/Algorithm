#include<iostream>
using namespace std;

//	제거 2초
//	채우기 1초

int land[501][501];
int main(void)
{
	int mint = 99999999;
	int minh = 99999999;
	int time;
	int N, M, B;
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> land[i][j];

	for (int h = 0; h <= 256; h++)
	{
		int remove = 0;
		int stack = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (land[i][j] > h)		//	제거해야할 블록 개수
					remove += land[i][j] - h;
				else if (land[i][j] == h)		//	같으면 통과
					continue;
				else if (land[i][j] < h)		//	쌓아야 할 블록 개수
					stack += h - land[i][j];
			}
		}
		if (remove + B >= stack)		//	"제거해서 인벤토리에 추가한 블록 + 원래 있던 블록 >= 쌓아야할 블록 개수" 라면..
		{
			time = remove * 2 + stack;
			if (time <= mint)
			{
				mint = time;
				minh = h;		//	현재 설정된 높이가 최소높이가 됨
			}
		}
	}
	cout << mint << ' ' << minh;
	return 0;
}