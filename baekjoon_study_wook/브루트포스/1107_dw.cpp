// 1107 리모컨
// 솔루션 봄
#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int n,m;
int num[10];

bool check(int cha){
    string s = to_string(cha);
    for(int i=0; i<s.size(); i++){
        if(num[s[i]-'0']) return false;
    }
    return true;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        num[tmp] = 1; 

    }
    int rst = abs(n-100);
    
    string s = to_string(n);
    for(int i=0; i<=1000000; i++){
        if(check(i)){
            // + - 누르는 수      번호 입력하는 수 의 합
            int tmp = abs(n-i) + to_string(i).length(); 
            rst = min(rst, tmp);
        }
    }

    cout << rst;
    return 0;
}