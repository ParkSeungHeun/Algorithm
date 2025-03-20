#include <iostream>

using namespace std;

int main() {
    
    int N, M;
    cin >> N >> M;

    int map[101][101] = { 0, };

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                continue;
            }

            map[i][j] = 1e9;
        }
    }

    for (int i = 1; i <= M; i++) {
        int s, e;
        cin >> s >> e;

        map[s][e] = 1;
        map[e][s] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            // k를 통해 가는 
            for (int j = 1; j <= N; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    int tmp = 21e8;
    int result = 0;

    for (int i = 1; i <= N; i++) {
        int sum = 0;

        for (int j = 1; j <= N; j++) {
            sum += map[i][j];
        }

        if (sum < tmp) {
            result = i;
            tmp = sum;
        }
    }

    cout << result;
   

    return 0;
}
