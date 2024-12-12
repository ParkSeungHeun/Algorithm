#include <iostream>
#include <vector>
#include <stack>

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

	int N;
	cin >> N;
	
	vector<int> A(N, 0);
	vector<char> result;

	for (int i = 0; i < A.size(); i++) {
		cin >> A[i];
	}

	stack<int> stack;
	int num = 1;
	bool flag = true;

	for (int i = 0; i < A.size(); i++) {
		int tmp = A[i];

		if (tmp >= num) {
			while (tmp >= num) {
				stack.push(num);
				num++;
				result.push_back('+');
			}

			stack.pop();
			result.push_back('-');
		}
		else {
			int n = stack.top();

			stack.pop();

			if (n > tmp) {
				cout << "NO" << '\n';
				flag = false;
				break;
			}
			else {
				result.push_back('-');
			}
		}
	}

	if (flag) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << '\n';
		}
	}
	
	return 0;
}
