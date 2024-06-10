#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	string str;
	string result;

	cin >> N >> str;
	
	for (int i = 0; i < str.length(); i += N) {
		result.append(str.substr(i, 1));
	}

	cout << result;

	return 0;
}



