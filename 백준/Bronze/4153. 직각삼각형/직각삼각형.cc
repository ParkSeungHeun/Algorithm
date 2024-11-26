#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) break;

		if (a * a == b * b + c * c) {
			cout << "right" << '\n';
			continue;
		}

		if (b * b == a * a + c * c) {
			cout << "right" << '\n';
			continue;
		}

		if (c * c == a * a + b * b) {
			cout << "right" << '\n';
			continue;
		}

		cout << "wrong" << '\n';
	}
	
	return 0;
}