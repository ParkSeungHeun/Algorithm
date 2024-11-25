#include <iostream>
#include <string>

using namespace std;

int main()
{
	// 최대 1000글자

	int tmp_arr[1001][1001] = { 0, };

	string str1;
	string str2;

	cin >> str1 >> str2;
	
	int result = 0;

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			if (str1[i] == str2[j]) {
				tmp_arr[i + 1][j + 1] = tmp_arr[i][j] + 1;
			}
			else {
				tmp_arr[i + 1][j + 1] = max(tmp_arr[i][j + 1], tmp_arr[i + 1][j]);
			}
		}
	}

	cout << tmp_arr[str1.length()][str2.length()];
	return 0;
}