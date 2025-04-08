#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int Judge(int arr[][100], int y, int x);

int main() {
    int T = 10;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        int N;
        cin >> N;

        vector<int> index;

        int arr[100][100] = { 0, };

        for (int i = 0; i < 100; i++) {
            int num;
            cin >> num;

            if (num == 1) {
                index.push_back(i);
            }

            arr[0][i] = num;
        }

        for (int i = 1; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> arr[i][j];
            }
        }

        int result = 0;

        int sum = 21e8;

        for (int i = 0; i < index.size(); i++) {
            int height = 0;
            int tmp_result = i;

            int x = i; 

            int tmp_sum = 0;

            while (height < 99) {
                int judge = Judge(arr, height, index[x]);

                if (judge == 2) {
                    // 오른 쪽 이동
                    tmp_sum += abs(index[x] - index[x + 1]);
                    x++;
                }
                else if (judge == 1) {
                    tmp_sum += abs(index[x] - index[x - 1]);
                    x--;
                }

                height++;
            }

            if (tmp_sum < sum) {
                result = i;
                sum = tmp_sum;
            }

        }
        
        cout << "#" << test_case << " " << index[result] << '\n';

    }
    return 0;
}

// straight : 0, left : 1, right : 2
int Judge(int arr[][100], int y, int x)
{
    if (x + 1 < 100) {
        if (arr[y][x + 1] == 1) {
            return 2;
        }
    }

    if (x - 1 >= 0) {
        if (arr[y][x - 1] == 1) {
            return 1;
        }
    }

    return 0;
}