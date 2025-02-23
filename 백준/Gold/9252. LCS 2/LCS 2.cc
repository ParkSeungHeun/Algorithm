#include<bits/stdc++.h>
#define N 1001
using namespace std;
 
int s[N][N];
char a[N],b[N];
 
void print(int i,int j){
    if(s[i][j]==0)return;
    if(a[i-1]==b[j-1]){
        print(i-1, j-1);
        cout<<a[i-1];
    }else s[i-1][j]>s[i][j-1]?print(i-1,j):print(i,j-1);
}
 
int main(){
    cin>>a>>b;
    int i,j=0;
    for(i=0;a[i];++i)for(j=0;b[j];++j){
        if(a[i]==b[j])s[i+1][j+1]=s[i][j]+1;
        else s[i+1][j+1]=max(s[i][j+1],s[i+1][j]);
        
    }
    cout<<s[i][j]<<'\n';
    print(i,j);
    return 0;
}
 