#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long Power(int A, int B, int C);

int main()
{
    long long A, B, C;
    cin >> A >> B >> C;

    cout << Power(A, B, C);

    return 0;
}

long long Power(int A, int B, int C) 
{
    if (B == 0) return 1;
    if (B == 1) return A % C;

    long long ret = Power(A, B / 2, C) % C;
    if (B % 2 == 0) {
        return ret * ret % C;
    }
    else {
        return ret * ret % C * A % C;
    }
}