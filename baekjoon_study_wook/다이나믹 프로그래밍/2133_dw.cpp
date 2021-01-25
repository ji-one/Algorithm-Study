// 2133 타일 채우기  
#include <iostream>

using namespace std;

int n;
int dp[31];
int main(){
	cin >> n;
	dp[0] = 1;
	dp[2] = 3;
	
	for(int i = 4;i <=n; i+=2){
		dp[i] = dp[i-2] * 3 ;
		for(int j=4; j<=i; j+=2){
			dp[i] += dp[i-j]*2;
		}
		
	}
	cout << dp[n];
	return 0;
}
