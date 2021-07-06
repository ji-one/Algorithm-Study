// 16637 괄호 추가하기 -- 솔루션

#include <iostream>
#include <string>
#include <vector>
#define MIN -2100000000
using namespace std;

int n, ans = MIN;
string s;

int cal(int a, int b, char oper) {
    switch (oper)
    {
    case '+' :
        a+=b;
        break;
    case '-' :
        a-=b;
        break;
    case '*' :
        a*=b;
        break;
    }
    return a;
}

void dfs(int idx, int currentVal) {
    if(idx > n-1) {
        if(currentVal > ans) {
            ans = currentVal;
        }
        return ;
    }
    
    char oper = idx == 0 ? '+' : s[idx-1];

    if(idx+2 < n) {
        // 괄호 계산한 값
        int temp = cal(s[idx]-'0', s[idx+2]-'0', s[idx+1]);
        dfs(idx+4, cal(currentVal, temp, oper));
    }

    // 괄호 X
    dfs(idx+2, cal(currentVal, s[idx] - '0', oper));
    
}

int main(){
    cin >> n >> s;
    
    dfs(0,0);
    cout << ans;

    return 0;
}