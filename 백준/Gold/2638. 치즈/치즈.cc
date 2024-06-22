#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int y;
    int x;
};

int Solution(vector<int> map[], int N, int M);
void BFS(vector<int> map[], int N, int M, int y, int x);

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> map[100];
    int cheese = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;

            map[i].push_back({ num });
            if (num == 1) {
                cheese++;
            }
        }
    }

    int count = 0;

    BFS(map, N, M, 0, 0);

    while (cheese > 0) {
        // Solution 실행
        int ret = Solution(map, N, M);

        cheese -= ret;
        count++;
    }

    cout << count;
    return 0;
}

int Solution(vector<int> map[], int N, int M)
{
    int direction_x[4] = { 0, 0, 1, -1 };
    int direction_y[4] = { 1, -1, 0, 0 };

    queue<Node> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == -1) continue;

            int count = 0;
            for (int k = 0; k < 4; k++) {
                int nx = j + direction_x[k];
                int ny = i + direction_y[k];

                if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

                if (map[ny][nx] == -1) {
                    count++;
                }
            }

            if (count >= 2) {
                q.push({ i, j });
            }
        }
    }

    int cheese = q.size();
    for (int i = 0; i < cheese; i++) {
        Node now = q.front();
        q.pop();

        BFS(map, N, M, now.y, now.x);
    }
    // 리턴 : 치즈 녹은 양
    return cheese;
}

void BFS(vector<int> map[], int N, int M, int y, int x)
{
    int direction_x[4] = { -1, 1, 0, 0 };
    int direction_y[4] = { 0, 0, -1, 1 };

    queue<Node> q;
    q.push({ y, x });
    map[y][x] = -1;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + direction_y[i];
            int nx = now.x + direction_x[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

            if (map[ny][nx] == -1 || map[ny][nx] == 1) continue;

            q.push({ ny, nx });
            map[ny][nx] = -1;
        }
    }
}