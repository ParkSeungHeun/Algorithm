#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int cost;
} Edge;

void Union(int parent[], int p1, int p2);
int Find(int parent[], int p1);
bool SameParent(int parent[], int p1, int p2);

int compare(const void* a, const void* b) {
    if (((Edge*)a)->cost > ((Edge*)b)->cost) return 1;
    if (((Edge*)a)->cost < ((Edge*)b)->cost) return -1;
    return 0;
}

int main() {
    int V, C;
    scanf("%d %d", &V, &C);

    Edge edges[100001];

    for (int i = 0; i < C; i++) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);

        edges[i].start = start;
        edges[i].end = end;
        edges[i].cost = cost;
    }

    int parent[10001];
    for (int i = 0; i <= V; i++) {
        parent[i] = i;
    }

    qsort(edges, C, sizeof(Edge), compare);

    int result = 0;
    int edge_count = 0;

    for (int i = 0; i < C; i++) {
        if (!SameParent(parent, edges[i].start, edges[i].end)) {
            Union(parent, edges[i].start, edges[i].end);
            result += edges[i].cost;
            edge_count++;
        }

        if (edge_count == V - 1) break;
    }

    printf("%d\n", result);
    return 0;
}

void Union(int parent[], int p1, int p2)
{
    p1 = Find(parent, p1);
    p2 = Find(parent, p2);

    if (p1 != p2) {
        parent[p2] = p1;
    }
}

int Find(int parent[], int p1)
{
    if (parent[p1] == p1) {
        return p1;
    }
    else {
        parent[p1] = Find(parent, parent[p1]);
        return parent[p1];
    }
}

bool SameParent(int parent[], int p1, int p2)
{
    p1 = Find(parent, p1);
    p2 = Find(parent, p2);

    if (p1 == p2) {
        return true;
    }
    else {
        return false;
    }
}