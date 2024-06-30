#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int end;
    int cost;

    bool operator<(Node right) const {
        return cost > right.cost;
    }
};

int Solution(vector<Node> map[], int N, int start, int end);

int main() {
    int N, E;
    cin >> N >> E;

    vector<Node> map[801];

    for (int i = 0; i < E; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;

        map[start].push_back({ end, cost });
        map[end].push_back({ start, cost });
    }

    int v1, v2;
    cin >> v1 >> v2;

    
    int result1 = Solution(map, N, 1, v1) + Solution(map, N, v1, v2) + Solution(map, N, v2, N);
    int result2 = Solution(map, N, 1, v2) + Solution(map, N, v2, v1) + Solution(map, N, v1, N);

    if (result1 >= 2e8 && result2 >= 2e8) {
        cout << -1;
        return 0;
    }

    if (result1 >= result2) {
        cout << result2;
    }
    else {
        cout << result1;
    }

    return 0;
}

int Solution(vector<Node> map[], int N, int start, int end)
{
    if (start == end) return 0;

    priority_queue<Node> pq;
    int arr[801] = { 0, };
    for (int i = 0; i <= N; i++) {
        arr[i] = 21e8;
    }

    arr[start] = 0;
    pq.push({ start, 0 });

    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        for (int i = 0; i < map[now.end].size(); i++) {
            Node next = map[now.end][i];

            int nextcost = arr[now.end] + next.cost;

            if (nextcost >= arr[next.end]) continue;

            arr[next.end] = nextcost;
            pq.push({ next.end, nextcost });
        }
    }

    return arr[end];
}
