#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    
    int N;
    cin >> N;

    int M;
    cin >> M;

    int arr[101][101] = { 0, };

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                arr[i][j] = 0;
                continue;
            }
            arr[i][j] = 1e9;
        }
    }

    for (int i = 1; i <= M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;

        arr[start][end] = min(arr[start][end], cost);
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (arr[j][k] > arr[j][i] + arr[i][k]) {
                    arr[j][k] = arr[j][i] + arr[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == 1e9) {
                cout << 0 << " ";
            }
            else {
                cout << arr[i][j] << " ";
            }
            
        }
        cout << '\n';
    }
    return 0;
}

