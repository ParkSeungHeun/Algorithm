#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[5][5][100001]; // DP 배열
int arr[5][5] = {
    {0, 2, 2, 2, 2},
    {0, 1, 3, 4, 3},
    {0, 3, 1, 3, 4},
    {0, 4, 3, 1, 3},
    {0, 3, 4, 3, 1}
};

vector<int> v;

// DP 기반 재귀 함수
int Solution(int left, int right, int count) {
    if (count == v.size()) return 0;

    int& ret = dp[left][right][count];
    if (ret != -1) return ret; // 이미 계산된 경우 반환

    int t = v[count]; // 현재 이동해야 할 위치
    ret = min(Solution(t, right, count + 1) + arr[left][t],
        Solution(left, t, count + 1) + arr[right][t]);

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp)); // DP 배열 초기화 (-1)

    while (true) {
        int num;
        cin >> num;
        if (num == 0) break; // 0이 입력되면 종료
        v.push_back(num);
    }

    cout << Solution(0, 0, 0);
    return 0;
}
