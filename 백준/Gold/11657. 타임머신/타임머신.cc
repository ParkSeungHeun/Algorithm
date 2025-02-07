#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

typedef struct {
    int start, end, cost;
} Edge;

Edge edges[6000]; // 최대 간선 수 (M)
long long dist[501];    // 거리 배열

void BellmanFord(int N, int M);

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // 간선 입력 받기
    for (int i = 0; i < M; i++) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        edges[i].start = start;
        edges[i].end = end;
        edges[i].cost = cost;
    }

    BellmanFord(N, M);
    return 0;
}

void BellmanFord(int N, int M) {
    // 거리 배열 초기화
    for (int i = 1; i <= N; i++) {
        dist[i] = INT_MAX;
    }
    dist[1] = 0; // 시작 노드는 1번

    // 벨만-포드 알고리즘 실행 (N-1번 반복)
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int u = edges[j].start;
            int v = edges[j].end;
            int cost = edges[j].cost;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
            }
        }
    }

    // 음수 사이클 확인 (N번째 루프)
    for (int j = 0; j < M; j++) {
        int u = edges[j].start;
        int v = edges[j].end;
        int cost = edges[j].cost;

        if (dist[u] != INT_MAX && dist[v] > dist[u] + cost) {
            printf("-1\n");
            return;
        }
    }

    // 결과 출력
    for (int i = 2; i <= N; i++) {
        if (dist[i] == INT_MAX) {
            printf("-1\n");
        }
        else {
            printf("%d\n", dist[i]);
        }
    }
}
