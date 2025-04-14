#include <iostream>
#include <vector>

using namespace std;

bool VerticalPalindrom(char map[][9], int N, int start, int height);
bool HorizonPalindrom(char map[][9], int N, int start, int weight);

int main() {
    int T = 10;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        int N;
        cin >> N;
        
        char map[9][9];

        for (int i = 0; i < 8; i++) {
            cin >> map[i];
        }

        int result = 0;

        // 높이 i,
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j <= 8 - N; j++) {
                if (VerticalPalindrom(map, N, j, i)) {
                    result++;
                }
            }
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j <= 8 - N; j++) {
                if (HorizonPalindrom(map, N, j, i)) {
                    result++;
                }
            }
        }
        
        cout << "#" << test_case << " " << result << '\n';

    }
    return 0;
}

bool VerticalPalindrom(char map[][9], int N, int start, int height)
{
    // 길이 4, 시작 2
    // 2 3 4 5
    for (int i = 0; i < N / 2; i++) {
        // 2 5, 3 4
        if (map[height][start + i] != map[height][start + N - 1 - i]) {
            return false;
        }
    }

    return true;
}

bool HorizonPalindrom(char map[][9], int N, int start, int weight)
{
    // 길이 4, 시작 2
    // 2 3 4 5
    for (int i = 0; i < N / 2; i++) {
        if (map[start + i][weight] != map[start + N - 1 - i][weight]) {
            return false;
        }
    }

    return true;
}
