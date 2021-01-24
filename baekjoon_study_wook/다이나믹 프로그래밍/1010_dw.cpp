// 1010 다리 놓기 --- 솔루션봄 
#include <iostream>
#include <cstring>
using namespace std;

int t,n,m;
int dp[31][31]; // [a][b] a에서 b 다리 경우의 수 

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=m ;i++){
			dp[1][i] = i;
		}
		
		for(int i=2; i<=n; i++){
			for(int j=i; j<=m; j++){
				for(int k=j; k>=i; k--){
					dp[i][j] += dp[i-1][k-1];
				}
				
			}
		}
		
		cout << dp[n][m] << '\n';
		
	}
	return 0;
}
