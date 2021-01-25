// 11052 카드 구매하기 
#include <iostream>

using namespace std;

int n;
int p[1001];
int dp[1001];
int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> p[i];
		dp[i] = p[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			if(i%j==0)
				dp[i] = max(dp[i], dp[j]*(i/j));
			dp[i] = max(dp[i], dp[i-j] + dp[j]);
		}
	}
	
	cout << dp[n];
	return 0;
}
