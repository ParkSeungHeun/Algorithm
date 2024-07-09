#include <iostream>

#include <vector>

#include <queue>

#include <math.h>

#include <algorithm>

using namespace std;

struct Shark {
    int y;
    int x;
    int speed;
    int direction;
    int size;
};

void Solution(Shark map[][101], int fisher, int y, int x, int* result);
void Capture(Shark map[][101], int fisher, int y, int x, int* result);
void Move(Shark map[][101], int y, int x);
int DirectionChange(int y, int x, int ny, int nx);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int y, x, M;
    cin >> y >> x >> M;

    Shark map[101][101] = { 0, };

    for (int i = 0; i < M; i++) {
        int y1, x1, speed, direction, size;
        cin >> y1 >> x1 >> speed >> direction >> size;

        map[y1 - 1][x1 - 1] = { y1 - 1, x1 - 1, speed, direction, size };
    }

    int result = 0;
    for (int i = 0; i < x; i++) {
        // 낚시꾼이 0 > 1 > 2 > ....
        Solution(map, i, y, x, &result);

    }

    cout << result;
    return 0;
}

// 상 : 1 하 : 2 우 : 3 좌 : 4
void Solution(Shark map[][101], int fisher, int y, int x, int* result)
{
    Capture(map, fisher, y, x, result);

    // 최대 속도를 넣어서 while문 돌려서 구현하자 !
    Move(map, y, x);
}

// 상어 잡기
void Capture(Shark map[][101], int fisher, int y, int x, int* result)
{
    for (int i = 0; i < y; i++) {
        // 생선이 있으면
        if (map[i][fisher].size > 0) {
            (*result) += map[i][fisher].size;
            // 초기화, 만약 오답이면 여기부터 체크합시다
            map[i][fisher] = { 0, 0, 0, 0, 0 };
            return;
        }
    }
}

void Move(Shark map[][101], int y, int x)
{
    int direction_x[4] = { 0, 0, 1, -1 };
    int direction_y[4] = { -1, 1, 0, 0 };

    Shark tmp_map[101][101] = { 0, }; 

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            tmp_map[i][j] = { 0, 0, 0, 0, 0 };
        }
    }

    // 아 ㅅㅂ 만나면 이네
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            // 상어가 없으면 넘어가기
            if (map[i][j].size == 0) continue;

            // 상어가 있으면 그 다음 좌표에 상어가 있는지 없는지 확인하고 
            if (map[i][j].size > 0) {
                int speed_count = 0;

                int speed_mod = map[i][j].speed;
                if (map[i][j].direction == 1 || map[i][j].direction == 2) {
                    speed_mod %= 2 * (y - 1);
                }
                else {
                    speed_mod %= 2 * (x - 1);
                }

                int nx = j;
                int ny = i;

                while (speed_count < speed_mod) {
                    nx += direction_x[map[i][j].direction - 1];
                    ny += direction_y[map[i][j].direction - 1];

                    // 만약 맵을 튀어나갔으면 방향 반대로 해서 앞으로 전진하게 하기
                    if (nx < 0 || nx >= x) {
                        map[i][j].direction = DirectionChange(y, x, ny, nx);
                        // 반대로 해서 두칸 이동하게 하기
                        nx += direction_x[map[i][j].direction - 1] * 2;
                    }

                    if (ny < 0 || ny >= y) {
                        map[i][j].direction = DirectionChange(y, x, ny, nx);
                        // 반대로 해서 두칸 이동하게 하기
                        ny += direction_y[map[i][j].direction - 1] * 2;
                    }

                    speed_count++;
                }

                // 상어가 없음
                if (tmp_map[ny][nx].size == 0) {
                    tmp_map[ny][nx] = { ny, nx, map[i][j].speed, map[i][j].direction, map[i][j].size };
                    map[i][j] = { 0, 0, 0, 0, 0 };
                }
                // 상어가 있으면 크기 비교 후 둘 중 하나 삭제
                else {
                    if (tmp_map[ny][nx].size > map[i][j].size) {
                        map[i][j] = { 0, 0, 0, 0, 0 };
                    }
                    else {
                        // 덮어씌우깅
                        tmp_map[ny][nx] = { ny, nx, map[i][j].speed, map[i][j].direction, map[i][j].size };
                        map[i][j] = { 0, 0, 0, 0, 0 };
                    }
                }


            }
        }
    }

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            map[i][j] = tmp_map[i][j];
        }
    }
}

int DirectionChange(int y, int x, int ny, int nx)
{
    if (nx < 0) {
        return 3;
    }
    else if (nx >= x) {
        return 4;
    }

    if (ny < 0) {
        return 2;
    }
    else if (ny >= y) {
        return 1;
    }
}

