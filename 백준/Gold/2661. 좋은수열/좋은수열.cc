#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

void Solution(string str, int n, int cnt, string* result);
bool Check(string str);

int main() {
    
    int n;
    cin >> n;

    string result = "";
    Solution("", n, 0, &result);

    cout << result;
    return 0;
}

void Solution(string str, int n, int cnt, string* result)
{
    // 나쁜 수열이거나 답이 나왔으면 탈출,
    if (!Check(str) || (*result).size() > 0) {
        return;
    }

    // 답이 나왔으면
    if (n == cnt) {
        (*result) = str;
        return;
    }
    Solution(str + "1", n, cnt + 1, result);
    Solution(str + "2", n, cnt + 1, result);
    Solution(str + "3", n, cnt + 1, result);
}

bool Check(string str)
{
    for (int i = 1; i <= str.size() / 2; i++) {
        if (str.substr(str.size() - i) == str.substr(str.size() - 2 * i, i)) {
            return false;
        }
    }

    return true;
}