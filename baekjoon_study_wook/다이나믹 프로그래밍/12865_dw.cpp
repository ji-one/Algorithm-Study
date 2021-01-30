// 12865 평범한 배낭 -- 솔루션 봄
/*
F[A][B] = C
A번째 물건까지, 가방의 무게가 B일때 가방에 든 가치는 C 이다

1. 물건을 넣을 수 있는지 없는지 확인
2. 넣을 수 있지만 넣을 것인지 안넣을 것인지 확인
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
int w[101];
int v[101];
int dp[101][100001];
int main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> w[i] >> v[i];
    }
    
    // i번째 물건에서 가방 무게 j 만들기
    // 물건들을 1번부터 n번까지 탐색
    for(int i=1; i<=n; i++){

        // 가방의 무게를 1~K까지 탐색
        for(int j=1; j<=k; j++){    
            // 현재 물건의 무게가 만들고자 하는 가방의 무게보다는 
            // 크거나 같아야 가방에 넣을 수 있다.
            if(j >= w[i]) 
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][k];
    return 0;
}