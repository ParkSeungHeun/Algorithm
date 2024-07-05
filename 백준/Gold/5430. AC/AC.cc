#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		// 명령어와 N
		string command;
		int N;
		cin >> command >> N;

		deque<string> dq;

		// 배열
		string arr;
		cin >> arr;

		char tmp_string[4];
		int count = 0;

		if (arr.size() == 2) {
			arr.clear();
		}

		for (int j = 1; j < arr.size(); j++) {
			if (arr[j] >= '0' && arr[j] <= '9') {
				tmp_string[count] = arr[j];
				count++;
			}
			else {
				if (count == 0) continue;

				tmp_string[count] = '\0';
				dq.push_back((string)(tmp_string));
				count = 0;
			}
		}

		// 초기 : false;
		bool flag = false;
		bool flag2 = true;

		for (int i = 0; i < command.size(); i++) {
			char com = command[i];
			
			switch (com) {
			case 'R':
				flag = !flag;
				break;

			case 'D':
				if (dq.size() > 0) {
					if (flag == false) {
						dq.pop_front();
					}
					else {
						dq.pop_back();
					}
				}
				else {
					flag2 = false;
				}
				break;
			}

		}

		if (flag2 == false) {
			cout << "error" << '\n';
		}
		else {
			cout << "[";

			if (!flag) {
				for (int i = 0; i < dq.size(); i++) {
					cout << dq[i];

					if (i < dq.size() - 1) {
						cout << ",";
					}
				}
			}
			else {
				for (int i = dq.size() - 1; i >= 0; i--) {
					cout << dq[i];

					if (i > 0) {
						cout << ",";
					}
				}
			}
			
			cout << "]" << '\n';
		}
		

	}
	return 0;
}