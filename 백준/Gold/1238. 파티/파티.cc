#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace ::std;

struct Node {
    int point;
    int cost;
};

void dijkstra(vector<Node> road[], int visited[], int start);

int main() {
    // N, M, X
    // X : 파티 열리는 곳
    // N : 학생, 최대 1000
    // M : 도로, 최대 10000
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    int M;
    int X;

    cin >> N >> M >> X;

    vector<Node> road[1001];
    vector<Node> reverse_road[1001];

    int visited[1001];
    int reverse_visited[1001];

    for (int i = 0; i <= N; i++) {
        visited[i] = 21e8;
        reverse_visited[i] = 21e8;
    }

    for (int i = 0; i < M; i++) {
        int s, e, c;
        cin >> s >> e >> c;

        road[s].push_back({ e, c });
        reverse_road[e].push_back({ s, c });
    }
    
    dijkstra(road, visited, X);
    dijkstra(reverse_road, reverse_visited, X);

    int max = 0;

    for (int i = 1; i <= N; i++) {
        if (visited[i] + reverse_visited[i] > max) {
            max = visited[i] + reverse_visited[i];
        }
    }
    
    cout << max;
}

void dijkstra(vector<Node> road[], int visited[], int start)
{
    visited[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        
        int now = q.front();
        q.pop();

        // 다음 좌표로~~
        for (int i = 0; i < road[now].size(); i++) {
            int nextcost = road[now][i].cost + visited[now];

            // 더 비싸면 넘어가기
            if (nextcost >= visited[road[now][i].point]) continue;

            visited[road[now][i].point] = nextcost;
            q.push(road[now][i].point);
        }
    }
}