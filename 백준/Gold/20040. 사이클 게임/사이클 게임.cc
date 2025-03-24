#include <iostream>
#include <vector>

using namespace std;

void Union(int arr[], int num1, int num2);
int Find(int arr[], int num);
bool Parent(int arr[], int num1, int num2);

int main() {
    
    int N, M;
    cin >> N >> M;
    
    int point[600001];

    for (int i = 0; i <= N; i++) {
        point[i] = i;
    }


    for (int i = 1; i <= M; i++) {
        int s, e;
        cin >> s >> e;

        if (Parent(point, s, e)) {
            cout << i;
            return 0;
        }
        
        Union(point, s, e);
    }

    cout << 0;

    return 0;
}

void Union(int arr[], int num1, int num2)
{
    int p1 = Find(arr, num1);
    int p2 = Find(arr, num2);
    
    if (p1 == p2) {
        return;
    }
    else {
        arr[p2] = p1;
    }
}

int Find(int arr[], int num)
{
    if (arr[num] == num) {
        return num;
    }
    else {
        return arr[num] = Find(arr, arr[num]);
    }
}

bool Parent(int arr[], int num1, int num2)
{
    int p1 = Find(arr, num1);
    int p2 = Find(arr, num2);

    if (p1 != p2) {
        return false;
    }
    else {
        return true;
    }
}