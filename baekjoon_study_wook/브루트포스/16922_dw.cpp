// 16922 로마 숫자 만들기

#include <iostream>
#include <algorithm>

using namespace std;

int n, rst;
int num[1001];
int rome[] = {1,5,10,50};

void dfs(int cnt, int sum, int idx) {
    if(cnt>n) return ;
    if(idx == 4) {
        if(cnt==n && !num[sum]) {
            num[sum] = 1;
            rst++;
            // cout << sum << ' ';
        }
        return ;
    }
    
    for(int i=0; i<=n; i++) {
        if(cnt + i <=n) {
            
            dfs(cnt + i, sum + rome[idx] * i, idx+1);
        }
    }
}

int main(){
    cin >> n;

    dfs(0,0,0);
    cout << rst;

    return 0;
}