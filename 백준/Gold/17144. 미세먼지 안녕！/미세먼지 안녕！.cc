#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int y;
    int x;
};

void Particle(int map[][1000], int R, int C);
void Clean(int map[][1000], vector<Node>& v, int R, int C);

int main() {
    
    int R, C, T;
    cin >> R >> C >> T;

    int map[1000][1000] = { 0, };
    vector<Node> v;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            
            if (map[i][j] == -1) {
                v.push_back({ i, j });
            }
        }
    }

    for (int i = 0; i < T; i++) {
        Particle(map, R, C);
        Clean(map, v, R, C);
    }

    int result = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] <= 0) continue;
            result += map[i][j];
        }
    }

    cout << result;

    return 0;
}

void Particle(int map[][1000], int R, int C)
{
    int tmp_map[1000][1000] = { 0, };
    int direction_x[4] = { 0, 0, 1, -1 };
    int direction_y[4] = { 1, -1, 0, 0 };
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 0) continue;

            if (map[i][j] == -1) {
                tmp_map[i][j] = -1;
                continue;
            }

            int part = map[i][j] / 5;
            int count = 0;

            for (int k = 0; k < 4; k++) {
                int ny = i + direction_y[k];
                int nx = j + direction_x[k];

                // 맵 튀나가면 
                if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;

                // 공기청정기면
                if (map[ny][nx] == -1) continue;

                tmp_map[ny][nx] += part;
                count++;
            }

            tmp_map[i][j] += map[i][j] - part * count;

        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            map[i][j] = tmp_map[i][j];
        }
    }

}

void Clean(int map[][1000], vector<Node>& v, int R, int C)
{
    for (int num = 0; num < 2; num++) {
        Node now = v[num];

        switch (num)
        {
        case 0:
            map[now.y - 1][now.x] = 0;

            for (int i = now.y - 1; i > 0; i--) {
                map[i][now.x] = map[i - 1][now.x];
            }

            for (int i = now.x; i < C - 1; i++) {
                map[0][i] = map[0][i + 1];
            }

            for (int i = 0; i < now.y; i++) {
                map[i][C - 1] = map[i + 1][C - 1];
            }

            for (int i = C - 1; i > now.x + 1; i--) {
                map[now.y][i] = map[now.y][i - 1];
            }
            map[now.y][now.x + 1] = 0;
            break;

        case 1:
            map[now.y + 1][now.x] = 0;

            for (int i = now.y + 1; i < R - 1; i++) {
                map[i][now.x] = map[i + 1][now.x];
            }

            for (int i = 0; i < C - 1; i++) {
                map[R - 1][i] = map[R - 1][i + 1];
            }

            for (int i = R - 1; i > now.y - 1; i--) {
                map[i][C - 1] = map[i - 1][C - 1];
            }

            for (int i = C - 1; i > now.x + 1; i--) {
                map[now.y][i] = map[now.y][i - 1];
            }
            map[now.y][now.x + 1] = 0;
            break;
        }
    }
    
}