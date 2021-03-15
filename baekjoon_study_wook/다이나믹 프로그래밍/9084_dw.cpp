// 9084 동전
/* solution
    dp[x] = y  x를 만들 수있는 경우의 수는 y
    dp[x] = dp[x-a]     x를 만들때 a가 마지막으로 사용되는 경우 
            + dp[x-b]   x를 만들때 b가 마지막으로 사용되는 경우
            ...
*/
#include <iostream>
#include <cstring>
using namespace std; 

int t,n,m;
int coin[21];
int dp[10001];  // i원을 만들 수 있는 경우의 수

int main(){
    cin >> t;
    while(t--){
        memset(coin, 0, sizeof(coin));
        memset(dp, 0, sizeof(dp));

        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> coin[i];
        }
        cin >> m;
        
        dp[0] = 1;
        // i번째 동전이 마지막으로 사용 되는 모든 경우의 수를 구함
        for(int i=1; i<=n; i++){
            // coin[i] 이전의 수는 만들 수 없는 상황이다.
            for(int j=coin[i]; j<=m; j++){
                dp[j] = dp[j] + dp[j-coin[i]];
            }
        }
        cout << dp[m] <<'\n';
    }

    return 0;
}