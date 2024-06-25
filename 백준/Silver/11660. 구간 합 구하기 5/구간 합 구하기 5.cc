#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int map[1025][1025] = { 0, };

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int num;
            cin >> num;
            if (j == 1) {
                map[i][j] = num;
            }
            else {
                map[i][j] = num + map[i][j - 1];
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        int sum = 0;

        for (int j = y1; j <= y2; j++) {
            sum += map[j][x2] - map[j][x1 - 1];
        }
        cout << sum << '\n';
    }

    return 0;
}
