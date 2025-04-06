#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N, M, k;
    vector<int> A; 
    vector<int> B;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> k;
        A.push_back(k);
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> k;
        B.push_back(k);
    }
    
    bool flag = true;
    vector<int> answer; 
    int max_A, A_idx, max_B, B_idx;
    while(1){
        while(1){
            if(A.size() == 0 || B.size() == 0){
                flag = false;
                break;
            }
            max_A = *max_element(A.begin(), A.end());
            A_idx = max_element(A.begin(), A.end()) - A.begin();
  
            max_B = *max_element(B.begin(), B.end());
            B_idx = max_element(B.begin(), B.end()) - B.begin();
  
            if(max_A == max_B){
                break;
            }
            else if(max_A > max_B){
                A.erase(A.begin()+A_idx);
            }
            else{
                B.erase(B.begin()+B_idx);
            }
        }
        if(flag == false){
            break;
        }
        answer.push_back(max_A);
        int temp = 0;
        
        for(int i = A_idx+1; i < A.size(); i++){
            A[temp] = A[i]; 
            temp++;
        }
        for(int i = 0; i < A_idx + 1; i++){
            A.pop_back(); 
        }
        temp = 0;
        for(int i = B_idx+1; i < B.size(); i++){
            B[temp] = B[i];
            temp++;
        }
        for(int i = 0; i < B_idx + 1; i++){
            B.pop_back();
        }
    }
    
    if(!answer.empty()){
        cout << answer.size() << "\n";
        for(auto c:answer){
            cout << c << " ";
        }
    }
    else{
        cout << 0;
    }
}