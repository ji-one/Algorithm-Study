// 2748 피보나치 수 2 
#include <iostream>

using namespace std;

int n;
long long dp[91];
void fibo(){
	dp[1] = 1;
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return ;
}
int main(){
	cin >> n;
	
	fibo();
	
	cout << dp[n] <<'\n';
	return 0;
}
