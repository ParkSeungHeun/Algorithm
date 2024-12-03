#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool Solution(unordered_map<char, int>& um, int A, int C, int G, int T);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S, P;
	cin >> S >> P;

	string str;
	cin >> str;

	int A, C, G, T;
	cin >> A >> C >> G >> T;

	unordered_map<char, int> um;

	for (int i = 0; i < P; i++) {
		um[str[i]] += 1;
	}

	int result = 0;

	for (int i = 0; i <= S - P; i++) {
		if (i == 0) {
			if (Solution(um, A, C, G, T)) {
				result++;
			}
			continue;
		}

		um[str[i - 1]] -= 1;
		um[str[i + P - 1]] += 1;

		if (Solution(um, A, C, G, T)) {
			result++;
		}
	}
	
	cout << result;
	return 0;
}

bool Solution(unordered_map<char, int>& um, int A, int C, int G, int T)
{
	if (um['A'] < A) {
		return false;
	}

	if (um['C'] < C) {
		return false;
	}

	if (um['G'] < G) {
		return false;
	}

	if (um['T'] < T) {
		return false;
	}

	return true;
}