#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node {
    int idx;
    int cost;

    bool operator<(Node right) const {
        return cost < right.cost;
    }
};

void Solution(vector<Node> map[], int item[], int n, int m, int idx, int* sum);

int main()
{
    // n : 지역 개수, m : 수색 범위, r : 길의 개수
    // 양방향 그래프
    int n, m, r;

    cin >> n >> m >> r;

    // 문제 설계 : pq를 하나 소환해서, 번호가 1일 때~~~~ 번호가 N일 때 까지 순회.
    // 1일때 ~ N일 때 최대 아이템수를 pq에 저장
    // N까지 돌깅
    // item[] : 1 ~ N 번호에 있는 아이템의 개수
    int item[101];
    for (int i = 1; i <=  n; i++) {
        cin >> item[i];
    }

    // 경로 입력
    // map : 모든 이어짐
    vector<Node> map[101];

    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;

        // 양방향
        map[a].push_back({ b, l });
        map[b].push_back({ a, l });
    }

    // 1 ~
    priority_queue<int> result;

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        // 마지막 pq 넣기
        Solution(map, item, n, m, i, &sum);
        result.push(sum);
    }
    
    cout << result.top();

    return 0;
}

// 맵, item 맵, idx : 시작점
void Solution(vector<Node> map[], int item[], int n, int m, int idx, int* sum)
{
    // 특정 점을 더 싸게 갈 수 있기 때문에.... dfs가 아닌 다익스트라를 해야 한다.
    // 코스트가 싼 대로 가기
    priority_queue<Node> pq;
    int arr[101];

    for (int i = 0; i <= 100; i++) {
        arr[i] = 21e8;
    }
    
    // 현재 위치에서 코스트는 0
    arr[idx] = 0;
    pq.push({ idx, 0});

    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        // 현재 뽑은 것 중에세 반복문을 돌 것 인데
        for (int i = 0; i < map[now.idx].size(); i++) {
            Node next = map[now.idx][i];
            int nextcost = arr[now.idx] + next.cost;
            
            // 이전에 기록되었던 코스트보다 비싸면 넘어가 <- 얘가 싸이클 방지
            if (arr[next.idx] <= nextcost) continue;

            // 더한 값이 m보다 비싸면 넘어가
            if (nextcost > m) continue;

            // 그게아니면 pq에 추가하고 arr갱신하고 ㄱㄱ
            pq.push({ next.idx, nextcost});
            arr[next.idx] = nextcost;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (arr[i] != 21e8) {
            (*sum) += item[i];
        }
    }

}


