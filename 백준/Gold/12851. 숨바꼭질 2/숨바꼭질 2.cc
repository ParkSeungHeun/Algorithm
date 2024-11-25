#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int map[100005];
    int tmp_result[100005];

    for (int i = 0; i < 100005; i++) {
        map[i] = 21e8;       // 큰 값으로 초기화
        tmp_result[i] = 0;   // 경로 수 초기화
    }

    map[N] = 0;
    tmp_result[N] = 1;       // 시작 위치는 방법 1개

    queue<int> q;
    q.push(N);

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        int next_positions[3] = {num + 1, num - 1, num * 2};

        for (int next : next_positions) {
            if (next >= 0 && next <= 100000) {
                if (map[next] > map[num] + 1) {
                    // 더 짧은 시간에 처음 도달한 경우
                    map[next] = map[num] + 1;
                    tmp_result[next] = tmp_result[num];
                    q.push(next);
                } else if (map[next] == map[num] + 1) {
                    // 같은 시간에 다른 경로로 도달한 경우
                    tmp_result[next] += tmp_result[num];
                }
            }
        }
    }

    cout << map[K] << '\n' << tmp_result[K];
    return 0;
}
