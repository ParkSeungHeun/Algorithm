#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int y;
    int x;

    bool operator<(Node right) const {
        if (x < right.x) {
            return true;
        }
        else if (x > right.x) {
            return false;
        }
        else {
            if (y < right.y) {
                return true;
            }
            else {
                return false;
            }
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Node> v;
    
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        v.push_back({ y, x });
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        cout << v[i].x << " " << v[i].y << '\n';
    }
    return 0;
}
