#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int idx = 0;
    int num = 0;

    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;

        if (s != "FizzBuzz" && s != "Fizz" && s != "Buzz") {
            idx = i;
            num = stoi(s);
        }
    }

    num += (3 - idx);

    if (num % 5 == 0 && num % 3 == 0) cout << "FizzBuzz\n";
    else if (num % 3 == 0) cout << "Fizz\n";
    else if (num % 5 == 0) cout << "Buzz\n";
    else cout << num << '\n';

    return 0;
}