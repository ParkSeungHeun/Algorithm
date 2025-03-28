#include <iostream>
#include <deque>

using namespace std;

int main() {

  // 첫 번째 연산 : pop_front
  // 두 번째 연산 : push_back(front) & pop_front
  // 세 번째 연산 : push_front(back) & pop_back
  // 왼쪽 또는 오른쪽으로 rotate 시킬 수 있고 front만 삭제 가능 
  // m개의 수를 삭제하는 데 필요한 최소 연산 횟수 구하기

  deque<int> dq; // n개의 원소를 담을 deque
  int idx; // 삭제할 원소가 있는 인덱스 
  int res = 0; // 정답

  int n, m, x;
  cin >> n >> m;

  for(int i = 1; i <= n; i++) 
    dq.push_back(i);

  while(m--) {
    cin >> x;

    for(int i = 0; i < dq.size(); i++) {
      if(dq[i] == x) {
        idx = i;
        break;
      }
    }

    // 앞에서부터
    if(idx <= dq.size() / 2) {
      while(1) {
        if(dq.front() == x) {
          dq.pop_front();
          break;
        }
        ++res;
        dq.push_back(dq.front());
        dq.pop_front();
      }
    } else { // 뒤에서부터
      while(1) {
        if(dq.front() == x) {
          dq.pop_front();
          break;
        }
        ++res;
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }

  cout << res;

  return 0;
}