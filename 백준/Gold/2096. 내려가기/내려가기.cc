#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int DP1[3] = {0, 0, 0};
    int DP2[3] = {0, 0, 0};
    int tempMax[3];
    int tempMin[3];

    for (int i = 0; i < N; i++) {
        int num[3];
        for (int j = 0; j < 3; j++) {
            cin >> num[j];
        }

        // 최대값 계산
        tempMax[0] = max(DP1[0], DP1[1]) + num[0];
        tempMax[1] = max({DP1[0], DP1[1], DP1[2]}) + num[1];
        tempMax[2] = max(DP1[1], DP1[2]) + num[2];
        for (int j = 0; j < 3; j++) {
            DP1[j] = tempMax[j];
        }

        // 최소값 계산
        tempMin[0] = min(DP2[0], DP2[1]) + num[0];
        tempMin[1] = min({DP2[0], DP2[1], DP2[2]}) + num[1];
        tempMin[2] = min(DP2[1], DP2[2]) + num[2];
        for (int j = 0; j < 3; j++) {
            DP2[j] = tempMin[j];
        }
    }

    int max_result = max({DP1[0], DP1[1], DP1[2]});
    int min_result = min({DP2[0], DP2[1], DP2[2]});

    cout << max_result << " " << min_result;
    return 0;
}
