// 2624 동전 바꿔주기
// solution`
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, k;


// dp[i][cost] : i번째 동전을 사용하여 cost 를 만드는 경우의 수
int dp[101][10001]; 

int main(){
    cin >> t >> k;

    vector<pair<int,int>> v(k+1);   // {금액, 개수}
    for(int i=1; i<=k; i++){  
        int p, n;
        cin >> p >> n;
        v[i] = {p,n};   
    }
    sort(v.begin()+1, v.end());

    dp[0][0] = 1; // 0 을 만드는 수는 1가지
    // i 번째 동전 
    for(int i = 1; i<=k; i++){
        // 0 ~ i의 동전 개수
        for(int j = 0; j<=v[i].second; j++){
            // 만들어야 하는 cost 
            for(int l = 0; l<=t; l++){
                if(v[i].first * j + l > t) break;
                dp[i][v[i].first * j + l] += dp[i-1][l];
            }
        }
    }
    for(int i=1; i<=k; i++){
        for(int j=0; j<=t; j++){
            cout << dp[i][j] <<' ';
        }
        cout << '\n';
    }

    cout << dp[k][t];

    return 0;
}