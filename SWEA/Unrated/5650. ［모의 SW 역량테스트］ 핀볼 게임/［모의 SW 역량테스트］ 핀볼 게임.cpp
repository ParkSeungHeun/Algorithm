#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

struct WarmNode {
    int y;
    int x;
    int num;

    bool operator<(WarmNode right) const {
        return num < right.num;
    }
};

void Solution(int map[][100], int N, vector<WarmNode> warm, int y, int x, int* result);
void DirectionChangeJudge(int num, int* d, int N, int ny, int nx);

int main() {

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        int N;
        cin >> N;

        int map[100][100] = { 0, };

        // 0 : 길
        // 모양 벽 : 1, 2, 3, 4
        // 네모벽 : 5
        // 웜홀 : 6, 7, 8, 9, 10;
        // 블랙홀 : -1

        vector<WarmNode> warm;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];

                if (map[i][j] >= 6 && map[i][j] <= 10) {
                    warm.push_back({ i, j, map[i][j] });
                }

            }
        }

        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {

                if (map[i][j] == 0) {
                    Solution(map, N, warm, i, j, &result);
                }

            }
        }

        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}

// 상 : 0, 우 : 1, 하 : 2, 좌 : 3
// 만약 숫자가 0~5라면 DrictionChangeJudge
// 만약 숫자가 6~10이라면 WarmHall
// 만약 숫자가 -1이면 break
// 
// 
void Solution(int map[][100], int N, vector<WarmNode> warm, int y, int x, int* result)
{
    int direction_y[4] = { -1, 0, 1, 0 };
    int direction_x[4] = { 0, 1, 0, -1 };

    // 4방향으로 보내기
    for (int i = 0; i < 4; i++) {
        int count = 0;
        int tmp_x = x;
        int tmp_y = y;
        int d = i;

        // DirectionChangeJudge에 값, 방향인자, 전체크기, 다음 좌표를 주면 알아서 방향을 계산해서 줌.
        while (1) {
            tmp_x += direction_x[d];
            tmp_y += direction_y[d];

            // 시작지점으로 돌아오면 break;
            if (tmp_x == x && tmp_y == y) break;

            // 칸 넘어가면 방향 바꾸고 튕기는거 보정하고 contunue;
            if (tmp_x < 0 || tmp_x >= N || tmp_y < 0 || tmp_y >= N) {
                DirectionChangeJudge(0, &d, N, tmp_y, tmp_x);
                count++;
                continue;
            }

            // 1~5 벽이면 방향바꾸고 튕기는거 올리고 continue;
            if (map[tmp_y][tmp_x] > 0 && map[tmp_y][tmp_x] < 6) {
                DirectionChangeJudge(map[tmp_y][tmp_x], &d, N, tmp_y, tmp_x);
                count++;
                continue;
            }

            // 블랙홀으로 들어가면 break;
            if (map[tmp_y][tmp_x] == -1) break;

            // 웜홀 경우
            if (map[tmp_y][tmp_x] >= 6 && map[tmp_y][tmp_x] <= 10) {
                // 웜홀이 있는 벡터를 찾기
                for (int j = 0; j < warm.size(); j++) {
                    // 해당하는 웜홀에서, 좌표가 같으면 안됨
                    if (warm[j].num == map[tmp_y][tmp_x]) {
                        if (warm[j].x == tmp_x && warm[j].y == tmp_y) continue;

                        // 좌표가 다른 다음 웜홀이면 WarmHall
                        tmp_x = warm[j].x;
                        tmp_y = warm[j].y;
                        break;
                    }

                }

                continue;
                // 웜홀 후에는 continue로 끝내주어야 한다.
            }


        }


        if ((*result) < count) {
            (*result) = count;
        }
    }
}

void DirectionChangeJudge(int num, int* d, int N, int ny, int nx)
{
    // 튀어나가는 것에 대한 처리
    if (nx < 0) {
        (*d) = 1;
        return;
    }

    if (nx >= N) {
        (*d) = 3;
        return;
    }

    if (ny < 0) {
        (*d) = 2;
        return;
    }

    if (ny >= N) {
        (*d) = 0;
        return;
    }
    // 칸에 대한 처리
    switch (num) {

    case 0: {
        break;
    }

          // 1번 모양일 땐 아래로 내려오고 있을 때 방향 오른, 오른에선 위
    case 1: {
        if ((*d) == 2) {
            (*d) = 1;
        }
        else if ((*d) == 3) {
            (*d) = 0;
        }
        else {
            (*d) = ((*d) + 2) % 4;
        }

        break;
    }

          // 2번 모양일 땐 위로 올라올 때 오른쪽 보내기
    case 2: {
        if ((*d) == 0) {
            (*d) = 1;
        }
        else if ((*d) == 3) {
            (*d) = 2;
        }
        else {
            (*d) = ((*d) + 2) % 4;
        }

        break;
    }

    case 3: {
        if ((*d) == 0) {
            (*d) = 3;
        }
        else if ((*d) == 1) {
            (*d) = 2;
        }
        else {
            (*d) = ((*d) + 2) % 4;
        }

        break;
    }

    case 4: {
        if ((*d) == 2) {
            (*d) = 3;
        }
        else if ((*d) == 1) {
            (*d) = 0;
        }
        else {
            (*d) = ((*d) + 2) % 4;
        }

        break;
    }

    case 5: {
        (*d) = ((*d) + 2) % 4;
        break;
    }
    }

}
