#include <iostream>

using namespace std;

int main() {

	int time[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };

	string s;
	int ans = 0;

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		ans += time[s[i] - 'A'];
	}
	
	cout << ans;
	

	return 0;
}