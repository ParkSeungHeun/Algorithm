#include <iostream>

using namespace std;

int main() {
    int T = 10;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        // 덤프 횟수
        int N = 0;
        cin >> N;

        int max = 0;
        int min = 1;

        // 각 층에 상자가 몇개 있는 지 알려주는 배열
        int floor[101] = { 0, };
        for (int i = 0; i < 100; i++) {
            int height;
            cin >> height;

            if (max < height) {
                max = height;
            }

            for (int j = 1; j <= height; j++) {
                floor[j]++;
            }
        }

        // 두 곳의 
        int tmp = 0;
        int storage = 0;

        while (true) {
            int num = 100 - floor[min];

            if (tmp + num > N) {
                // 채워야 하는 것 보다 채울 수 있는 횟수가 적은 경우 = 못채우는 경우
                // storage = 옮길 수 있는 수
                storage = N - tmp;
                min--;
                break;
            }

            tmp += num; 
            min++;
        }

        while (true) {
            // num = 높은 층에서 옮길 수 있는 블록의 개수
            // 높은 층에 있는 것들을 채워넣기
            int num = floor[max];
                

            // 계속 채워넣다가
            if (tmp - num < 0) {
                if (tmp - num + storage > 0) {
                    max--;
                }
                break;
            }
            
            tmp -= num;
            max--;
        } 

        cout << "#" << test_case << " " << max - min << '\n';
    }
    return 0;
}

