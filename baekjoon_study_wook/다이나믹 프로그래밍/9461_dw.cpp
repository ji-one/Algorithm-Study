// 9461 �ĵ��� ���� 
#include <iostream>

using namespace std;

int t,n;
long long dp[101]; 
int main(){
	cin >> t;
	
	while(t--){
		cin>> n;
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 2;
		dp[4] = 2;
		
		for(int i=5; i<n; i++){
			dp[i] = dp[i-1] + dp[i-5];
		}
		
		cout << dp[n-1] << '\n';
		
	}
	return 0;
} 
