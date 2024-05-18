#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <cstring>

using namespace std;

int VerticalCheck(int map[][20], int N, int X, int idx);
int HorizonCheck(int map[][20], int N, int X, int idx);

int main()
{
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        // N : 전체 크기, X : 활주로 최소 길이
        int N, X;
        cin >> N >> X;

        // 최소한 X만큼 같은 높이를 유지하야 하고, 
        // 사이드 에는 1만큼 높아야 한다 ~~
        // 추가로, 자기보다 커야한다 ~~
        // 먼저 사이드가 자신보다 큰 지 체크하고 만든다 ~~
        int map[20][20] = { 0 };

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        int result = 0;

        for (int i = 0; i < N; i++) {
            result += VerticalCheck(map, N, X, i);
            result += HorizonCheck(map, N, X, i);
        }

        cout << "#" << test_case << " " << result << '\n';
    }
    return 0;
}

// 가로 체크
int VerticalCheck(int map[][20], int N, int X, int idx)
{
    // N이 6, X가 2 체크할 수 있는 경우 : 5
    // 이렇게 체크 ~~!
    int count = 0;
    int judge = 0;

    bool visited[20] = { false };

    for (int i = 0; i < N - 1; i++) {
        if (map[idx][i] == map[idx][i + 1]) continue;

        judge++;
    }

    for (int i = 0; i < N - X + 1; i++) {
        bool flag = true;
        int tmp = map[idx][i];

        for (int j = i; j < i + X; j++) {
            if (tmp != map[idx][j]) {
                flag = false;
                break;
            };
        }

        if (flag == false) continue;

        // 만약 평지다 ~~ 그러면 좌 우 체크 ~~ 더 커야해 ~~
        // 같은데 0보다 인덱스가 커야해 ~~
        // 이미 설치한 경사로면 넘어가 ~~
        if (visited[i] == true) continue;

        if (i + X < N) {
            if (map[idx][i + X] == tmp + 1) {
                for (int j = i; j < i + X; j++) {
                    visited[j] = true;
                }
                count++;
                continue;
            }
        }

        if (i - 1 >= 0) {
            if (map[idx][i - 1] == tmp + 1) {
                count++;
                for (int j = i; j < i + X; j++) {
                    visited[j] = true;
                }
            }
        }

       
    }


    if (judge == count) {
        return 1;
    }
    else {
        return 0;
    }
}

int HorizonCheck(int map[][20], int N, int X, int idx)
{
    // N이 6, X가 2 체크할 수 있는 경우 : 5
    // 이렇게 체크 ~~!
    int count = 0;
    int judge = 0;

    bool visited[20] = { false };

    for (int i = 0; i < N - 1; i++) {
        if (map[i][idx] == map[i + 1][idx]) continue;

        judge++;
    }

    for (int i = 0; i < N - X + 1; i++) {
        bool flag = true;
        int tmp = map[i][idx];

        for (int j = i; j < i + X; j++) {
            if (tmp != map[j][idx]) {
                flag = false;
                break;
            };
        }

        if (flag == false) continue;
        if (visited[i] == true) continue;
        // 만약 평지다 ~~ 그러면 좌 우 체크 ~~ 더 커야해 ~~
        // 같은데 0보다 인덱스가 커야해 ~~
        if (i + X < N) {
            if (map[i + X][idx] == tmp + 1) {
                count++;
                for (int j = i; j < i + X; j++) {
                    visited[j] = true;
                }
                continue;
            }
        }

        if (i - 1 >= 0) {
            if (map[i - 1][idx] == tmp + 1) {
                count++;
                for (int j = i; j < i + X; j++) {
                    visited[j] = true;
                }
                
            }
        }

        
    }


    if (judge == count) {
        return 1;
    }
    else {
        return 0;
    }
}