#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool Solution(int num);

int main()
{
    int N;
    cin >> N;

    int count = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num == 1) continue;

        if (Solution(num)) {
            count++;
        }
    }

    cout << count;

    return 0;
}

bool Solution(int num)
{
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}
