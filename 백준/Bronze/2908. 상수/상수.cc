#include <iostream>
#include <string>

using namespace std;

int main() {

	string a, b;
	
	cin >> a >> b;

	string res;

	for (int i = 2; i >= 0; i--) {
		if (a[i] > b[i]) {
			res = a;
			break;
		}
		else if (a[i] < b[i]) {
			res = b;
			break;
		}
	}

	for (int i = 2; i >= 0; i--) {
		cout << res[i];
	}

	 

	return 0;
}