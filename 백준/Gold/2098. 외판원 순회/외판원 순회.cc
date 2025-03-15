#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int N;
int dist[16][16];
int dp[16][1 << 16];

int TSP(int current, int visited) {
    if (visited == (1 << N) - 1) {
        return dist[current][0] ? dist[current][0] : INF;
    }

    if (dp[current][visited] != -1) {
        return dp[current][visited];
    }

    dp[current][visited] = INF;

    for (int next = 0; next < N; next++) {
        if (visited & (1 << next) || dist[current][next] == 0) continue;
        dp[current][visited] = min(dp[current][visited],
            TSP(next, visited | (1 << next)) + dist[current][next]);
    }

    return dp[current][visited];
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dist[i][j];
        }
    }

    fill(&dp[0][0], &dp[15][1 << 16], -1);

    cout << TSP(0, 1) << endl;
    return 0;
}
