#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>

using namespace std;

struct Node {
	int num;
	int idx;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;
	deque<Node> dq;

	for (int i = 0; i < N; i++) {
		int now = 0;
		cin >> now;

		while (dq.size() && dq.back().num > now) {
			dq.pop_back();
		}

		dq.push_back({ now, i });

		if (dq.front().idx <= i - L) {
			dq.pop_front();
		}

		cout << dq.front().num << " ";
	}
	return 0;
}
