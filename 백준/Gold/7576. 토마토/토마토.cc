#include <iostream>
#include <queue> // use bfs algorithm
#include <stdio.h> // use printf, scanf
#include <cstring> // use memset
 
#define MAX_SIZE 1000 + 1
 
using namespace std;
 
struct tomato {
    int y, x;
};
 
queue<tomato> q;
 
// 우,하,좌,상
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };
 
int n, m, result = 0;
int graph[MAX_SIZE][MAX_SIZE];
 
bool IsInside(int ny, int nx) {
    return (0 <= nx && 0 <= ny && nx < m && ny < n);
}
 
void bfs(void) {
    while (!q.empty()) {
        // 큐의 현재 원소(익은 토마토(1))를 꺼내기
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
 
        // 해당 위치의 주변을 확인
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
 
            // 지도를 벗어나지 않고, 익지않은 토마토(0)라면
            if (IsInside(ny,nx) == 1 && graph[ny][nx] == 0) {
                graph[ny][nx] = graph[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }
}
 
int main() {
    /* 토마토 농장(그래프)의 크기 입력 (가로/세로)*/
    scanf("%d %d", &m, &n);
 
    /* 그래프 정보 입력*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1) { // 익은토마토(1) -> 큐
                q.push({ i, j });
            }
        }
    }
 
    /* 그래프를 BFS를 통해 탐색 */
    bfs();
 
    /* 날짜 계산 및 출력  */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 익지않은 토마토(0)가 존재할 경우
            if (graph[i][j] == 0) { 
                printf("-1\n");
                return 0;
            }
            // 토마토는 다 익었는데, 얼마만에 익었는지?
            if (result < graph[i][j]) {
                result = graph[i][j];
            }
        }
    }
    printf("%d\n", result-1);
    return 0;
}
