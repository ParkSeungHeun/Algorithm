#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

struct Node {
    int end;
    int cost;

    bool operator<(Node right) const {
        return cost > right.cost;
    }
};

int Solution(vector<Node> map[], int n, int start, int end);

int main() {

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        // n : 지점 개수 m : 도로 개수, t : 목적지 후보 개수
        // s : 테러리스트 출발지, g h 테러리스트가 지나가는 것을 확인한 두 지점
        int n, m, t;
        int s, g, h;

        cin >> n >> m >> t >> s >> g >> h;

        vector<Node> map[2001];

        // 경로 넣기~~
        for (int i = 0; i < m; i++) {
            int start, end, cost;
            cin >> start >> end >> cost;

            map[start].push_back({ end, cost });
            map[end].push_back({ start, cost });
        }

        vector<int> hubo;

        for (int i = 0; i < t; i++) {
            int num;
            cin >> num;

            hubo.push_back(num);
        }

        sort(hubo.begin(), hubo.end());

        for (int i = 0; i < t; i++) {
            // 직으로 가는 길의 비용
            int direct = Solution(map, n, s, hubo[i]);

            // 꼭 g->h를 거쳐 가는 길의 비용
            // 아 ~~ 뭐가 더 가까운 지 ~~

            int no_direct = Solution(map, n, g, h);

            if (Solution(map, n, s, g) > Solution(map, n, s, h)) {
                no_direct += Solution(map, n, s, h) + Solution(map, n, g, hubo[i]);
            }
            else {
                no_direct += Solution(map, n, s, g) + Solution(map, n, h, hubo[i]);
            }

            if (direct == no_direct) {
                cout << hubo[i] << " ";
            }
        }
        cout << '\n';

    }
    return 0;
}

// 해당 점까지 가는 비용을 반환해주는 다이크 스트라 ~~
int Solution(vector<Node> map[], int n, int start, int end)
{
    priority_queue<Node> pq;
    int arr[2001] = { 0 };
    
    for (int i = 1; i <= n; i++) {
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

            // nectcost가 더 크면 넘어가기 ~~
            if (arr[next.end] <= nextcost) continue;

            // 그게 아니면 다시 pq에 넣기 ~~
            pq.push({ next.end, nextcost });
            arr[next.end] = nextcost;
        }
    }

    return arr[end];
}