#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <cstring>

using namespace std;

struct Node {
    int y;
    int x;
};

void Solution(int map[][15], int N, int M, int D, int arrow1, int arrow2, int arrow3, int* result);
void BFS(int map[][15], queue<Node>& ener, int N, int M, int y, int x, int D);
void Move(int map[][15], int N, int M);

int main()
{
    // N : 세, M : 가, D : 사정거리
    int N, M, D;
    cin >> N >> M >> D;

    int map[16][15] = { 0, };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    // 궁수의 좌표를 넣기 ~~ 조합
    int tmp_map[16][15] = { 0, };
    int result = 0;

    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {

                for (int n = 0; n < N; n++) {
                    for (int m = 0; m < M; m++) {
                        tmp_map[n][m] = map[n][m];
                    }
                }

                Solution(tmp_map, N, M, D, i, j, k, &result);
            }
        }
    }

    cout << result;
    return 0;
}

// 궁수 세명의 좌표
void Solution(int map[][15], int N, int M, int D, int arrow1, int arrow2, int arrow3, int* result)
{
    // 가장 가까우면서 적이 왼쪽
    int count = 0;

    // 최대사거리 : N - D
    for (int high = 0; high < N; high++) {
        bool check[4] = { false };

        queue<Node> ener;

        // 쏘세요 ~~
        BFS(map, ener, N, M, N, arrow1, D);
        BFS(map, ener, N, M, N, arrow2, D);
        BFS(map, ener, N, M, N, arrow3, D);

        while (!ener.empty()) {
            Node now = ener.front();
            ener.pop();

            if (map[now.y][now.x] == 1) {
                count++;
                map[now.y][now.x] = 0;
            }
        }

        Move(map, N, M);
        
    }
    
    if (count > (*result)) {
        (*result) = count;
    }
}
// 궁수의 사정거리를 계산하여, 공격할 수 있는 사정거리 담기
// 그 중에서 가장 거리가 가까우면서, 왼쪽에 있는 적을 0으로 만들기
void BFS(int map[][15], queue<Node>& ener, int N, int M, int y, int x, int D)
{
    // 사정거리 내로 몹이 있으면 true, 없으면 false
    int direction_x[3] = { -1, 0, 1 };
    int direction_y[3] = { 0, -1, 0 };

    int count = 1;
    bool visited[16][15] = { false };

    queue<Node> q;
    q.push({ y, x });
    visited[y][x] = true;

    while (count <= D) {
        int num = q.size();
        bool flag = false;

        for (int i = 0; i < num; i++) {
            Node now = q.front();
            q.pop();

            for (int i = 0; i < 3; i++) {
                int ny = now.y + direction_y[i];
                int nx = now.x + direction_x[i];

                // 튀 나가면 끝
                if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

                // 방문했으면 끗
                if (visited[ny][nx] == true) continue;

                // 그게 아니라면 바로 ㄱㄱ
                visited[ny][nx] = true;
                q.push({ ny, nx });
                // 몹이 있다면 ~~
                if (map[ny][nx] == 1) {
                    ener.push({ ny, nx });
                    return;
                }
            }
        }
        count++;
    }

}

void Move(int map[][15], int N, int M)
{
    // 맨 아래 초기화
    for (int i = 0; i < M; i++) {
        map[N][i] = 0;
    }

    // 움직이깅~~
    for (int i = 0; i < M; i++) {
        for (int j = N - 1; j >= 1; j--) {
            map[j][i] = map[j - 1][i];
        }
    }

    // 맨 위 초기화
    for (int i = 0; i < M; i++) {
        map[0][i] = 0;
    }
}