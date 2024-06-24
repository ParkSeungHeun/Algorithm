#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int DP[1005][3];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> DP[i][j];
        }
    }

    for (int i = 1; i < N; i++) {
        DP[i][0] += min(DP[i - 1][1], DP[i - 1][2]);
        DP[i][1] += min(DP[i - 1][0], DP[i - 1][2]);
        DP[i][2] += min(DP[i - 1][0], DP[i - 1][1]);
    }

    int ret = min(DP[N - 1][0], DP[N - 1][1]);
    cout << min(ret, DP[N - 1][2]);

    return 0;
}
