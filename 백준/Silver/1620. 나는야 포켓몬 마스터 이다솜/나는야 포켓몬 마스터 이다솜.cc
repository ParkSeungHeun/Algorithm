#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

string pokemon[100000];

int main() {
	map<string, int> P;  
	int N;               // 도감에 수록된 포켓몬 수
	int M;               // 맞춰야 하는 문제의 수
	string input_name;   // 맞춰야 되는 문제 중 입력된 이름
	int input_num;       // 맞춰야 되는 문제 중 입력된 번호

	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> pokemon[i];
		P.insert(make_pair(pokemon[i], i));
	}

	for (int i = 0; i < M; i++) {
		cin >> input_name;

		// 1. 입력된 것이 숫자인 경우
		if (isdigit(input_name[0]) != 0) {
			input_num = stoi(input_name) - 1;
			cout << pokemon[input_num] << "\n";
		}

		// 2. 입력된 것이 문자인 경우
		else {
			auto index = P.find(input_name);
			cout << index->second + 1 << "\n";
		}
	}

	return 0;
}
