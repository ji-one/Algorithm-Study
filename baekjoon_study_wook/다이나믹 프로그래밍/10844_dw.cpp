// 10844 쉬운 계단 수
#include <iostream>

using namespace std;

int n;
int dp[101][10]; 
int main(){
	cin >> n;
	for(int i=0; i<10; i++){
		dp[1][i] = 1;
	}
	dp[0][1] = 1;
	for(int i=2; i<=n; i++){
		for(int j=1; j<10; j++){
			if(j == 1){
				dp[i][j] = (dp[i-2][j] + dp[i-1][j+1])%1000000000;
			}
			else if(j == 9){
				dp[i][j] = dp[i-1][j-1]%1000000000;
			}
			else{
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;	

			}

		}
	}
	
	int rst=0;
	for(int i=1; i<10; i++){
		rst= (rst+dp[n][i])%1000000000;
	}
	
	cout << rst%1000000000;
	return 0;
} 
