#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int N;
    cin >> N;

    vector<int> arr;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    int result = 0;
    
    for (int i = 0; i < N; i++) {
        int start = 0;
        int end = N - 1;

        while (start < end) {
            if (arr[start] + arr[end] == arr[i]) {
                if (start != i && end != i) {
                    result++;
                    break;
                }
                else if (start == i) {
                    start++;
                }
                else if (end == i) {
                    end--;
                }
            }
            else if (arr[start] + arr[end] < arr[i]) {
                start++;
            }
            else {
                end--;
            }
        }
    }

    cout << result;
    return 0;
}