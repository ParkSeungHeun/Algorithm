#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int BinarySearch(vector<int>& tree, int min, int max, int M);
long long Culculator(vector<int>& tree, int mid);

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> tree;
    int max = 0;
    int min = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num > max) {
            max = num;
        }

        tree.push_back(num);
    }

    // 이분 탐색을 진행하면서, 차이가 최소인 것인 파라미터일 때 스탑
    // 차이가 이전보다 커지면, 
    int result = BinarySearch(tree, min, max, M);
    cout << result;

    return 0;
}

int BinarySearch(vector<int>& tree, int min, int max, int M)
{
    int start = min;
    int end = max;
    int mid = 0;

    int prev = 0;
    int abs_value = 21e8;

    while (start <= end) {
        mid = (start + end) / 2;

        // cul = 잘린 나무의 총 길이
        long long cul = Culculator(tree, mid);

        if (cul == M) {
            return mid;
        }

        if (cul < M) {
            end = mid - 1;
            continue;
        }
        else {
            start = mid + 1;
        }

        if (abs(abs_value - M) > abs(cul - M)) {
            prev = mid;
            abs_value = cul;
        }

    }

    return prev;
}

long long Culculator(vector<int>& tree, int mid)
{
    long long sum = 0;

    for (int i = 0; i < tree.size(); i++) {
        if (tree[i] - mid >= 0) {
            sum += tree[i] - mid;
        }
    }

    return sum;
}