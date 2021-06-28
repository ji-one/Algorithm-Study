// 16987 계란으로 계란치기

#include <iostream>

using namespace std;

int n,rst;
int s[10];
int w[10];

void dfs(int idx, int cnt) {    // 계란번호, 깨진 개수
    
    if(idx == n) {
        if(rst < cnt) {
            rst = cnt;
        }
        // cout << cnt << ' ';
        return ;
    }
    if(s[idx] <= 0) {
        dfs(idx+1, cnt);
        return ;
    };

    bool no = true;
    for(int i=0; i<n; i++) {

        if(i == idx) continue;
        if(s[i] > 0) {
            no = false;
            s[i] -= w[idx];
            s[idx] -= w[i];
            if(s[i] <= 0 ) {
                cnt++;
            }
            if(s[idx] <= 0 ) {
                cnt++;
            }
            dfs(idx+1, cnt);
            if(s[i] <= 0 ) {
                cnt--;
            }
            if(s[idx] <= 0 ) {
                cnt--;
            }
            s[i] += w[idx];
            s[idx] += w[i];
        }

    }

    if(no) {    //깨진 계란이 없을때
        dfs(idx+1, cnt);
        return ;
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s[i] >> w[i];
    }

    dfs(0, 0);
    cout << rst;
    return 0;
}