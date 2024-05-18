#include <iostream>
#include <vector>
using namespace std;

int nodeCnt, edgeCnt;
vector<int> v[1000];
int visited[1000];
int cnt;

void func(int now)
{
    if (visited[now]) {
        return;
    }
    visited[now] = 1;
    cnt++;

    for (int i = 0; i < v[now].size(); i++)
    {
        int to = v[now][i];
        func(to);
    }
}

int main()
{
    cin >> nodeCnt >> edgeCnt;
    for (int i = 0; i < edgeCnt; i++)
    {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    func(1);
    cout << cnt - 1 << endl;
}