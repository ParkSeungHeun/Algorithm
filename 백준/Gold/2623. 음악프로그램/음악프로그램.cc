#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001

using namespace std;
// 위상정렬
void Solution(int entry[], vector<int> v[], int N);

int main() {
    
    int N, M;
    cin >> N >> M;

    int entry[MAX] = { 0, };
    vector<int> v[MAX];

    for (int i = 0; i < M; i++) {
        vector<int> tmp;
        int num = 0;
        cin >> num;

        for (int j = 0; j < num; j++) {
            int s;
            cin >> s;

            tmp.push_back(s);
        }

        for (int j = 0; j < tmp.size(); j++) {
            for (int k = j + 1; k < tmp.size(); k++) {
                v[tmp[j]].push_back(tmp[k]);
                entry[tmp[k]]++;
            }
        }
    }

    Solution(entry, v, N);

    return 0;
}

void Solution(int entry[], vector<int> v[], int N)
{
    queue<int> q;
    // 우선순위가 0인것들은 우선 넣기
    for (int i = 1; i <= N; i++) {
        if (entry[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        result.push_back(num);

        for (int i = 0; i < v[num].size(); i++) {
            int next = v[num][i];
            entry[next]--;

            if (entry[next] == 0) {
                q.push(next);
            }
        }
    }

    // 만약 사이즈가 N이 아니라면, 답이 아님
    if (result.size() != N) {
        cout << 0;
    }
    else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << '\n';
        }
    }
}