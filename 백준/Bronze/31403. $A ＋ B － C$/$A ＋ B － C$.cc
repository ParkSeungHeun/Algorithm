#include <iostream>
using namespace std;
string A, B, C;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B >> C;
    cout << stoi(A) + stoi(B) - stoi(C) << "\n";
    cout << stoi(A + B) - stoi(C);
    return 0;
}