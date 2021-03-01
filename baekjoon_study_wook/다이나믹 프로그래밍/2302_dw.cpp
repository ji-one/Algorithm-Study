// 2302 극장 좌석

#include <iostream>
#include <vector>
using namespace std;

int n,m;
long long dp[41];
int vip[41];
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        vip[a] = 1;
    }
    dp[0] = 1;
    dp[1] = 1;
    
    long long tmp = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int x=0;
    for(int i=1; i<=n; i++){
        if(vip[i] == 1){
            tmp *= dp[x];
            x=0;
        }
        else{
            x++;
        }
    }
    tmp *= dp[x];
    cout << tmp;
    return 0;
}