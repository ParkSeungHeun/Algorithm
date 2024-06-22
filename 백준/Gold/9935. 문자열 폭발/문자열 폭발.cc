#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    vector<char> stack;

    string str;
    cin >> str;

    string boom_str;
    cin >> boom_str;

    int pointer = -1;

    for (int i = 0; i < str.size(); i++) {
        stack.push_back(str[i]);
        pointer++;

        if (pointer < boom_str.size() - 1) {
            continue;
        }

        bool flag = true;

        for (int j = pointer - boom_str.size() + 1; j < pointer + 1; j++) {
            if (stack[j] != boom_str[j - pointer + boom_str.size() - 1]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            for (int j = 0; j < boom_str.size(); j++) {
                stack.pop_back();
                pointer--;
            }
        }
    }

    if (stack.size() == 0) {
        cout << "FRULA";
    }
    else {
        for (int i = 0; i < stack.size(); i++) {
            cout << stack[i];
        }
    }
    
    return 0;
}

