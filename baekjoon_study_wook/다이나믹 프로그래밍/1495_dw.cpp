// 1495 기타리스트

#include <iostream>

using namespace std;

int n,s,m;
int v[101];
bool dp[101][1001];

int main() {
    cin >> n >> s >> m;

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    if(s + v[0] <= m) dp[0][s + v[0]] = true;
    if(s - v[0] >= 0) dp[0][s - v[0]] = true;

    for(int i=1; i<n; i++) {
        for(int j=0; j<=m; j++) {
            if(dp[i-1][j] == true) {
                if(j + v[i] <= m) dp[i][j + v[i]] = true;
                if(j - v[i] >= 0) dp[i][j - v[i]] = true;
            }
        }
    } 

    int answer = -1;
    for(int i=0; i<=m; i++) {
        if(dp[n-1][i] == true) {
            answer = i;
        }
    }
    
    cout << answer;
    return 0;
}