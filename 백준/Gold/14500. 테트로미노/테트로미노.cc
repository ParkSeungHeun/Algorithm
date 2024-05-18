#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <cstring>

// 민코딩의 차윤이의 도형 맞추기 게임이 생각나는 ~~~~ 문제
using namespace std;

void Solution(int map[][500], int N, int M, int* max);

int main()
{
    int N, M;
    cin >> N >> M;

    int map[500][500] = { 0, };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int max = 0;
    
    Solution(map, N, M, &max);

    cout << max;
    return 0;
}

// MAP, N, M, *result
void Solution(int map[][500], int N, int M, int* max)
{
    // 1 + 2 + 2 + 4 + 4
    int direction_x[19][4] = {
        {0, 1, 0, 1},
        {0, 1, 2, 3},
        {0, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 2, 2},
        {0, 0, 0, -1},
        {0, -1, -2, -2},
        {0, 0, 1, 1},
        {0, 1, 1, 2},
        {0, 1, 1, 2},
        {0, 0, 1, 0},
        {0, -1, -1, -2},
        {0, 0, -1, 0},
        {0, 0, 0, -1},
        {0, 1, 2, 2},
        {0, 0, 0, 1},
        {0, -1, -2, -2},
        {0, 0, -1, -1},
        {0, 1, 1, 2}
    };

    int direction_y[19][4] = {
        {0, 0, 1, 1},
        {0, 0, 0, 0},
        {0, 1, 2, 3},
        {0, 1, 2, 2},
        {0, 0, 0, -1},
        {0, -1, -2, -2},
        {0, 0, 0, 1},
        {0, 1, 1, 2},
        {0, 0, -1, -1},
        {0, 0, 1, 0},
        {0, -1, -1, -2},
        {0, 0, -1, 0},
        {0, 1, 1, 2},
        {0, 1, 2, 2},
        {0, 0, 0, 1},
        {0, -1, -2, -2},
        {0, 0, 0, -1},
        {0, 1, 1, 2},
        {0, 0, 1, 1}
    };

    // 사각형
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            for (int k = 0; k < 19; k++) {
                int tmp_sum = 0;

                for (int l = 0; l < 4; l++) {
                    int nx = direction_x[k][l] + j;
                    int ny = direction_y[k][l] + i;

                    if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

                    // 그게 아니면 계산해서 
                    tmp_sum += map[ny][nx];
                }

                if (tmp_sum > (*max)) {
                    (*max) = tmp_sum;
                }
            }

        }
    }
}

