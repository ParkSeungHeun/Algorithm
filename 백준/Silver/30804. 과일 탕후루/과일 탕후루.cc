#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int N;
    cin >> N;

    vector<int> candy;

    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        
        candy.push_back(c);
    }

    int p1 = 0;
    int p2 = 0;
    
    int fruit[10] = { 0, };
    int fruit_various = 0;

    int result = 0;

    while (p2 < N) {
        
        if (fruit[candy[p2]] == 0) {
            fruit_various += 1;
        }

        fruit[candy[p2]] += 1;
        p2++;

        if (fruit_various > 2) {
            while (fruit_various > 2) {
                fruit[candy[p1]] -= 1;

                if (fruit[candy[p1]] == 0) {
                    fruit_various -= 1;
                }

                p1++;
            }
        }

        int sum = 0;

        for (int i = 1; i <= 9; i++) {
            sum += fruit[i];
        }

        if (sum > result) {
            result = sum;
        }
        
    }

    cout << result;

    return 0;
}
