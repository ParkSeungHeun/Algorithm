#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int num;
    int cost;

    bool operator<(Node right) const {
        return cost < right.cost;
    }
};

using namespace std;

void Solution(vector<Node> map[], int arr[], int N, int start);

int main() {
    
    int N;
    cin >> N;

    int M;
    cin >> M;

    vector<Node> map[101];

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        map[a].push_back({ b, c });
    }

    int result[101][101] = { 0, };

    int arr[101] = { 0, };

    for (int i = 1; i <= N; i++) {

        // 방문배열 초기화
        for (int j = 1; j <= N; j++) {
            arr[j] = 21e8;
        }

        // 시작 ~ N
        Solution(map, arr, N, i);

        for (int j = 1; j <= N; j++) {
            // 갈 수 없으면 continue;
            if (arr[j] == 21e8) continue;

            result[i][j] = arr[j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}

void Solution(vector<Node> map[], int arr[], int N, int start)
{
    arr[start] = 0;
    priority_queue<Node> pq;
    pq.push({ start, 0 });

    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        for (int i = 0; i < map[now.num].size(); i++) {
            Node next = map[now.num][i];

            int nextcost = arr[now.num] + next.cost;

            if (arr[next.num] < nextcost) continue;

            arr[next.num] = nextcost;
            pq.push({ next.num, nextcost });
        }
    }
}
