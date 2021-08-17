// 13392 방법을 출력하지 않는 숫자 맞추기
// 솔루션


#include <iostream>
#include <string>
#include <algorithm>

#define MAX 987654321

using namespace std;

int n;
int before[10001];
int after[10001];
int dp[10001][10];  // dp[a][b] = c 
//      -> a : 현재 나사 b : 전 나사 왼쪽 회전 횟수 c : 최소 회전수
string a,b;

int main() {
    cin >> n;
    cin >> a >> b;
    for(int i=1; i<=n; i++) {
        before[i] = (a[i-1]-'0');
        after[i] = (b[i-1]-'0');   
    }
    fill(&dp[0][0], &dp[n][10], MAX);
    for(int i=0; i<10; i++) dp[0][i] = i;
    
    for(int i=1; i<=n; i++) {
        for(int j=0; j<10; j++) {
            // 왼쪽 회전 수 = 전 - 후 - 전나사 왼쪽 회전 수
            int lcnt = (after[i] - before[i] - j + 20) % 10;
            int rcnt = 10 - lcnt;
            // 현재 나사를 오른쪽으로 돌릴때
            dp[i][j] = min(dp[i][j], dp[i-1][j] + rcnt);
            // 현재 나사를왼쪽으로 돌릴때
            dp[i][(j+lcnt) %10] = min(dp[i][(j+lcnt)%10], dp[i-1][j] + lcnt);
        }
    }

    int ans = MAX;
    for(int i=0; i<10; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans;
    return 0;
}