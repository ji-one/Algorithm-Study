// 1535 안녕

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int l[21];  // 체력
int joy[21];  // 기쁨
int dp[21][101];    
// dp[a][b]=c  위치 a 까지 봤고 체력이 b 남았을 때 최대 기쁨 c


int main() {
    cin >> n;
    int answer = 0;
    for(int i=1; i<=n;i++) {
        cin >> l[i];
    }
    for(int i=1; i<=n; i++){
        cin >> joy[i];
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=0; j<100; j++) {
            dp[i][j] = dp[i-1][j];
            if(j - l[i] >= 0) {
                dp[i][j] = max(dp[i-1][j-l[i]] + joy[i], dp[i][j]);
                
            }
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer;

    
    return 0;
}