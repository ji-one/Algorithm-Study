// 1149 RGB °Å¸® 

#include <iostream>

using namespace std;
int n;
int hou[1001][3];
int dp[1001][3];
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> hou[i][0] >> hou[i][1] >> hou[i][2];
	}
	dp[0][0] = hou[0][0];
	dp[0][1] = hou[0][1];
	dp[0][2] = hou[0][2];
	
	for(int i=1; i<n; i++){
		dp[i][0] = hou[i][0] + min(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = hou[i][1] + min(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = hou[i][2] + min(dp[i-1][0], dp[i-1][1]);
		
	}
	
//	for(int i=0; i<n; i++){
//		cout << dp[i][0] << ' '<< dp[i][1] << ' ' << dp[i][2] << '\n';
//	}
	int rst = min(dp[n-1][0],min(dp[n-1][1], dp[n-1][2]));
	cout << rst;
	return 0;
} 
