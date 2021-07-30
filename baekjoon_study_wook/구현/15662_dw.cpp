// 15662 톱니바퀴 (2)

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int top[1001][9];
int T,k;
int visit[1001];

bool isInside(int x) {
    return x>=1 && x<=T;
}

bool check(int a, int b) {
    if(top[a][2] != top[b][6]) {
        return true;
    }
    return false;
}
void rotate(int n, int d) {
    visit[n] = 1;
    if(isInside(n-1) && !visit[n-1] && check(n-1, n)) {
        // cout << "left : " << n-1 << ' ' << n << '\n';
        rotate(n-1, 0-d);
        
    }

    if(isInside(n+1) && !visit[n+1] && check(n, n+1)) {
        // cout << "right : " << n << ' ' << n+1 << '\n';
        rotate(n+1, 0-d);
    }
    if(d == 1) {
        int tmp = top[n][7]; 
        for(int i=7; i>0; i--) {
            top[n][i] = top[n][i-1];
        }
        top[n][0] = tmp;
    } else if(d == -1) {
        int tmp = top[n][0]; 
        for(int i=0; i<7; i++) {
            top[n][i] = top[n][i+1];
        }
        top[n][7] = tmp;
    }

    return ;
}
int main() {
    
    cin >> T;

    for(int i=1; i<=T; i++) {
        string s;   // N극 0 S극 1
        cin >> s;
        for(int j=0; j<8; j++) {
            top[i][j] = s[j] - '0';
        }
    }

    cin >> k;
    for(int i=0; i<k; i++) {
        memset(visit, 0, sizeof(visit));
        
        int n, d;
        cin >> n >> d;
        rotate(n,d);
        
    }
    int rst = 0;
    for(int i=1; i<=T; i++) {
        if(top[i][0] == 1) {
            rst++;
        }
    }

    cout << rst;
    return 0;
}