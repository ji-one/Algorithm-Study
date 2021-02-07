// 11066 파일  합치기
// 솔루션 봄
#include <iostream>
#include <cstring>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

/*
dp[a][a] = sum[a] - sum[a-1]

dp[a][a+1] = sum[a+1] - sum[a-1]

dp[a][a+2] = min(dp[a][a] + dp[a+1][a+2], dp[a][a+1] + dp[a+2][a+2])
*/
int t,n;
int dp[501][501]; // dp[a][b] : a부터 b까지 페이지를 합친 최솟값
int sum[501]; // 0부터 a까지 페이지의 값을 더한 값
int cost[501]; // dp[a][a] = cost[a]
vector<int> v;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> cost[i];
            sum[i] = sum[i-1] + cost[i];
        }
        for(int d = 1; d < n; d++){
            for(int i = 1; i+d <=n; i++){
                int j = i+d;
                dp[i][j] = INT_MAX;

                for(int mid = i; mid<j; mid++){
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid+1][j] + sum[j] - sum[i-1]);

                }
            }
        }

        cout << dp[1][n] << '\n';
    }
    return 0;
}