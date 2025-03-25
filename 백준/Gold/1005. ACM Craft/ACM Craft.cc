#include <iostream>
#include <vector>

#define MAX 1001

using namespace std;

int cul(vector<int> cost[], int dp[], int arr[], int num);

int main() {
    
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        int N, K;
        cin >> N >> K;

        int arr[MAX] = { 0, };
        int dp[MAX] = { 0, };

        for (int i = 1; i <= N; i++) {
            int cost;
            cin >> cost;

            arr[i] = cost;
            dp[i] = -1;
        }

        vector<int> cost[MAX];

        for (int i = 1; i <= K; i++) {
            int s, e;
            cin >> s >> e;

            cost[e].push_back(s);
        }

        // cost에는 특정 건물을 지으려면 뭘 지어야 하는 지 적혀있음
        // 4를 골랐어. 그러면 cost[4]에 해당하는 건물 2와 3은 동시 진행이 가능

        int num;
        cin >> num;
        
        cout << cul(cost, dp, arr, num) << '\n';

    }

    return 0;
}

int cul(vector<int> cost[], int dp[], int arr[], int num)
{
    // arr[num] : 자신이 지어지는 시간
    if (dp[num] != -1) {
        return dp[num];
    }

    int tmp = 0;

    // 선행건물의 시간
    for (int i = 0; i < cost[num].size(); i++) {

        if (tmp < cul(cost, dp, arr, cost[num][i])) {
            tmp = cul(cost, dp, arr, cost[num][i]);
        }
        
    }

    tmp += arr[num];
    dp[num] = tmp;
    return tmp;
}