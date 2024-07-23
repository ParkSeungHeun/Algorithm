#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;//n번째 영화
	int result = 665;//제일 작은 종말의 수 666보다 작도록 초기화
	string temp;
	cin >> n;

	for (int i = 0; i < n; i++) {
		while (1) {
			result++;//result를 1씩 증가시키면서
			temp = to_string(result);//정수형 result를 문자열로 변환
			if (temp.find("666") != -1)//종말의 수 666을 포함하는지 확인
				break;//n번째 종말의 수를 찾으면 break
		}
	}
	cout << result << endl;
}