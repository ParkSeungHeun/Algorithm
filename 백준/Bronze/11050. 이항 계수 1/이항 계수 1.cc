#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int fac(int N);

int main() {
    int N, K;
    cin >> N >> K;

    if (N - K == 0) {
        cout << 1;
    }
    else {
        cout << fac(N) / ((fac(N - K) * fac(K)));
    }

    return 0;
}

int fac(int N)
{
    if (N == 1 || N == 0) {
        return 1;
    }

    return N * fac(N - 1);
}