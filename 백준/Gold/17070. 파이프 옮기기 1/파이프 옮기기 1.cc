#include <iostream>

using namespace std;

void Solution(int map[][16], int N, int y, int x, int direction, int* result);

int main()
{
    int N;
    cin >> N;

    // 0,0 부터 시작, 파이프 밀기
    int map[16][16] = { 0, };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    // 시작은 항상...
    int result = 0;
    Solution(map, N, 0, 1, 0, &result);

    cout << result;
    // 가로 : 0 세로 : 1 대각 : 2
    return 0;
}

void Solution(int map[][16], int N, int y, int x, int direction, int* result)
{
    // 끝가지 가면
    if (y == N - 1 && x == N - 1) {
        (*result)++;
        return;
    }

    // 가로 : 0 세로 : 1 대각 : 2
    int direction_x[3] = { 1, 0, 1 };
    int direction_y[3] = { 0, 1, 1 };

    for (int i = 0; i < 3; i++) {
        // 시작 방향이 가로 / 세로 / 대각 일 경우를 나누어야 한다.

        int nx = x + direction_x[i];
        int ny = y + direction_y[i];

        switch (direction) {
        case 0:
            // 만약 가로일 경우, 세로로 움직이지 못한다.
            if (i == 1) continue;

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            if (map[ny][nx] == 1) continue;

            if (i == 0) {
                Solution(map, N, ny, nx, i, result);
            }
            
            // 대각 이동
            if (i == 2) {
                if (map[y + 1][x] == 1 || map[y][x + 1] == 1) continue;
                Solution(map, N, ny, nx, i, result);
            }

            break;

        case 1:
            if (i == 0) continue;

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            if (map[ny][nx] == 1) continue;

            if (i == 1) {
                Solution(map, N, ny, nx, i, result);
            }

            // 대각 이동
            if (i == 2) {
                if (map[y + 1][x] == 1 || map[y][x + 1] == 1) continue;
                Solution(map, N, ny, nx, i, result);
            }
            break;

        case 2:

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            if (map[ny][nx] == 1) continue;

            // 직선 이동 둘다됨
            if (i == 1 || i == 0) {
                Solution(map, N, ny, nx, i, result);
            }

            // 대각 이동
            if (i == 2) {
                if (map[y + 1][x] == 1 || map[y][x + 1] == 1) continue;
                Solution(map, N, ny, nx, i, result);
            }

            break;
        }
    }
}