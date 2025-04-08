#include<iostream>
#include<vector>
 
using namespace std;
 
const int n = 100;
 
int d1(vector<vector<int>> &v) {
    int result = 0;
    for(int i = 0; i <n; i++){
        result += v[i][i];
    }
    return result;
}
 
int d2(vector<vector<int>> &v) {
    int result = 0;
    int row = n-1;
    for(int i = 0; i <n; i++){
        result+= v[row - i][i];
    }
    return result;
}
 
 
int row(vector<vector<int>> &v, int col){
    int result = 0;
    for(int i = 0; i < n; i++){
        result += v[i][col];
    }
    return result;
}
 
int col(vector<vector<int>> &v, int row){
    int result = 0;
    for(int i = 0; i < n; i++){
        result += v[row][i];
    }
    return result;
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int temp;
        cin >> temp;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j <n; j++) {
                cin >> v[i][j];
            }
        }
        int result = -1;
        for(int i = 0; i <n; i++){
            result = max(result, row(v, i));
            result = max(result, col(v, i));
        }
        result = max(result, d1(v));
        result = max(result, d2(v));
         
        cout << "#" << test_case << " " << result << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}