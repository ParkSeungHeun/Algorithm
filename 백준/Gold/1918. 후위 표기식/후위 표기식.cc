#include <iostream>
#include <stack>

using namespace std;

int Trans(char c);

int main() {
    
    string str;
    cin >> str;
    
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push(str[i]);
        }
        else if (str[i] == ')') {
            while (!s.empty()) {
                char c = s.top();
                s.pop();

                if (c == '(') break;

                cout << c;
            }
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {

            while (!s.empty() && Trans(s.top()) >= Trans(str[i])) {
                cout << s.top();
                s.pop();
            }

            s.push(str[i]);
        }
        else {
            cout << str[i];
        }
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    // ABC
    // *
    return 0;
}

int Trans(char c)
{
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else {
        return 0;
    }
}