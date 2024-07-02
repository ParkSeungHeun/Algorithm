#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Division(int N, int K);

int main() {
    int N, K;
    cin >> N >> K;
    
    cout << Division(N, K) << '\n' << N * K / Division(N, K);
    return 0;
}

int Division(int N, int K)
{
    int result = 0;

    for (int i = 1; i <= min(N, K); i++) {
        if (N % i == 0 && K % i == 0) {
            result = i;
        }
    }

    return result;
}
