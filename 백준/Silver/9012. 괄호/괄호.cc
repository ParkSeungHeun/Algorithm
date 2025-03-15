#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		string str;
		cin >> str;

		int judge = 0;

		for (int i = 0; i < str.size(); i++) {

			if (str[i] == '(') {
				judge++;
			}
			else {
				judge--;
			}

			if (judge < 0) break;
		}

		if (judge == 0) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
