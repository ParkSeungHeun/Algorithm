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

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        int K;
        string str;
        cin >> str >> K;

        queue<int> q[26];

        int result1 = 21e8;
        int result2 = -21e8;

        for (int i = 0; i < str.size(); i++) {
            int idx = str[i] - 'a';
            q[idx].push(i);

            if (q[idx].size() == K) {
                int dist = i - q[idx].front() + 1;

                result1 = min(dist, result1);
                result2 = max(dist, result2);

                q[idx].pop();
            }
        }

        if (result2 < 0) {
            cout << -1 << '\n';
        }
        else {
            cout << result1 << " " << result2 << '\n';
        }
    }

    return 0;
}
