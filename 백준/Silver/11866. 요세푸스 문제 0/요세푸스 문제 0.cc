#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int N, K;
    cin >> N >> K;

    int count = 0;
    bool visited[1001] = { 0, };

    int tmp = 0;
    int index = K - 1;
    
    vector<int> result;

    while (count < N) {
        // tmp가 0이되면 visited true 만들고 K - 1로 초기화
        if (tmp == 0) {
            visited[index] = true;
            tmp = K;
            count++;
            result.push_back(index + 1);

            continue;
        }

        index = (index + 1) % N;
        if (visited[index]) continue;
        tmp--;
    }
    
    cout << "<";

    for (int i = 0; i < result.size(); i++) {
        if (i == result.size() - 1) {
            cout << result[i];
        }
        else {
            cout << result[i] << ", ";
        }
    }

    cout << ">";

    return 0;
}

