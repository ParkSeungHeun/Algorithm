#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

struct Node {
    int start;
    int end;
    int cost;

    bool operator<(const Node& right) const {
        return cost > right.cost; // 최소 힙을 만들기 위해 반대로 비교
    }
};

struct Cost {
    int cost;
    int path;
};

void Solution(vector<Node> map[], int start, int end);

int main() {
    int N, M;
    cin >> N >> M;

    vector<Node> map[1001];

    for (int i = 0; i < M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;

        map[start].push_back({ start, end, cost });
    }

    int start, end;
    cin >> start >> end;

    Solution(map, start, end);

    return 0;
}

void Solution(vector<Node> map[], int start, int end)
{
    Cost arr[1001];

    // 배열 초기화 (INT_MAX 사용)
    for (int i = 0; i <= 1000; i++) {
        arr[i].cost = INT_MAX;
        arr[i].path = -1;
    }

    priority_queue<Node> pq;
    arr[start].cost = 0;
    arr[start].path = start;

    pq.push({start, start, 0});

    while (!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();

        // 최단 거리가 갱신되지 않은 경우 continue
        if (arr[cur.start].cost < cur.cost) continue;

        for (const auto& next : map[cur.start]) {
            int nextcost = next.cost + arr[cur.start].cost;

            if (arr[next.end].cost > nextcost) {
                arr[next.end].cost = nextcost;
                arr[next.end].path = cur.start;
                pq.push({next.end, next.end, nextcost});
            }
        }
    }

    cout << arr[end].cost << '\n';

    vector<int> result;
    int result_path = end;
    while (result_path != start) {
        result.push_back(result_path);
        result_path = arr[result_path].path;
    }
    result.push_back(start);

    cout << result.size() << '\n';
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
}
