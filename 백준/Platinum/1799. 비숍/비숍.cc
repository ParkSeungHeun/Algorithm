#include <iostream>
#include <vector>
using namespace std;

#define MAX 10

int N, board[MAX][MAX], maxBishop[2]; 
bool diag1[MAX * 2], diag2[MAX * 2]; // 대각선 방문 여부

void backtracking(int row, int col, int count, int color) {
    if (col >= N) { // 열이 끝나면 다음 행으로
        row++;
        col = (col % 2 == 0) ? 1 : 0; // 흑백 칸 구분
    }
    if (row >= N) { // 체스판 끝 도달
        maxBishop[color] = max(maxBishop[color], count);
        return;
    }

    // 비숍을 놓을 수 있는 경우
    if (board[row][col] && !diag1[row - col + N] && !diag2[row + col]) {
        diag1[row - col + N] = diag2[row + col] = true;
        backtracking(row, col + 2, count + 1, color);
        diag1[row - col + N] = diag2[row + col] = false;
    }

    // 비숍을 놓지 않는 경우
    backtracking(row, col + 2, count, color);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    // 흑과 백을 구분하여 두 번 탐색
    backtracking(0, 0, 0, 0); // 검은색 칸
    backtracking(0, 1, 0, 1); // 흰색 칸

    cout << maxBishop[0] + maxBishop[1] << endl;
    return 0;
}
