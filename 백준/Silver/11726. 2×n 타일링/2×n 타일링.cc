#include <iostream>

using namespace std;

int main() {
    
    int N;
    cin >> N;

    // N = 1, 1
    // N = 2, 2
    // N = 3, 3
    // f(n+1) = f(n) + f(n-1);
    int f[2000] = { 0, };
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;

    for (int i = 3; i <= N; i++) {
        f[i] = f[i - 1] + f[i - 2];
        f[i] = f[i] % 10007;
    }

    cout << f[N];
    return 0;
}
