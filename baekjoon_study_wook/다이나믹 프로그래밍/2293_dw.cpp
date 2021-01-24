// 2293 동전1
#include <iostream>

using namespace std;

int n,k;
int coin[101];
int dp[10001]; // dp[a] = b  a원을 만들 수 있는 경우의 수는 b 

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin>> coin[i];
	}
	dp[0] = 1;
	for(int i=0; i<n; i++){
		for(int j=coin[i]; j<=k; j++){
			dp[j] = dp[j] + dp[j-coin[i]];
		}
	}
	cout << dp[k];
	return 0;
} 
