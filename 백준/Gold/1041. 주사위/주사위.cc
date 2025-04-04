#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int arr[6] = { 0, };
    for (int i = 0; i < 6; i++) {
        int num;
        cin >> num;

        arr[i] = num;
    }

    int sum[6] = { 0, };
    sum[1] = 21e8;
    sum[2] = 21e8;

    // 0의 위치일 떈, 5와 붙어있지 x
    // 1의 위치일 땐, 4와 x
    // 2의 위치일 떈, 3과 x
    // 조합 ㄱㄱ
    for (int i = 0; i < 6; i++) {

        for (int j = 0; j < 6; j++) {
            if (i == j) continue;
            if (i + j == 5) continue;

            int tmp_sum = arr[j] + arr[i];

            if (tmp_sum < sum[1]) {
                sum[1] = tmp_sum;
            }
        }
    }
    
    int direction_dice[8][3] = {
        {0, 1, 2},
        {0, 1, 3},
        {0, 3, 4},
        {0, 2, 4},
        {5, 1, 3},
        {5, 1, 2},
        {5, 3, 4},
        {5, 2, 4}
    };

    for (int i = 0; i < 8; i++) {
        int tmp_sum = 0;

        for (int j = 0; j < 3; j++) {
            tmp_sum += arr[direction_dice[i][j]];
        }

        if (tmp_sum < sum[2]) {
            sum[2] = tmp_sum;
        }
    }
    
    sort(arr, arr + 6);

    sum[0] = arr[0];
    sum[4] = arr[0] + arr[1] + arr[2] + arr[3] + arr[4];

    long long result = 0;

    if (N == 1) {
        result = sum[4];
    }
    else if (N == 2) {
        result = sum[1] * 4 + sum[2] * 4;   
    }
    else {
        long long one = pow((N - 2), 2) * 5 + (N - 2) * 4;
        long long two = (N - 2) * 8 + 4;

        // 아랫면이 가려지지 않았을 경우
        // 2개의 면이 보이는거 : (N - 2) * 12
        // 1개의 면이 보이는거 : (N - 2) * 2 * 6
        // 3개의 면 : 8

        // 아랫면이 가려질 경우
        // 2개의 면이 보이는거 : (N - 2) * 8 + 4
        // 1개의 면이 보이는거 : (N - 2) ^ 2 * 5 + (N - 2) * 4
        // 3개의 면 : 4
        result = sum[0] * one + sum[1] * two + sum[2] * 4;
    }
    
    cout << result;
    return 0;
}

