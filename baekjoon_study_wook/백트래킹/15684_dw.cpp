// 15684 사다리 조작

#include <iostream>
#include <algorithm>

using namespace std;

int n,m,h, answer = 987654321;
int ladder[31][11];

bool check() {
    for(int j=1; j<=n; j++) {
        int x = j;
        for(int i=1; i<=h; i++) {
            if(ladder[i][x] == 1) {
                x = x+1;
            }else if(x-1 > 0 && ladder[i][x-1] == 1) {
                x = x-1;
            }
        }
        if(x != j) {
            return false;
        }
    }
    return true;
}

void dfs(int x, int cnt) {
    if(cnt > 3) return ;
    if(check()) {
        answer = min(answer, cnt);
        return ;
    }
    
    
    for(int i=x; i<=h; i++) {
        for(int j=1; j<n; j++) {
            if(ladder[i][j] == 1) continue;
            if(j-1>0 && ladder[i][j-1] == 1) continue;
            if(j+1<n && ladder[i][j+1] == 1) continue;
            ladder[i][j] = 1;
            
            dfs(i, cnt+1);
            ladder[i][j] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> h;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a>> b;
        ladder[a][b] = 1;   // a높이에서 b, b+1 다리 연결
    }
    dfs(1, 0);
    if(answer == 987654321) {
        cout << -1;
    } else  {
        cout << answer;
    }
    
    return 0;
}