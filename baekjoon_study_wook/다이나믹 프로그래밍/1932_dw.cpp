// 1932 Á¤¼ö »ï°¢Çü 
#include <iostream>

using namespace std;

//	dp[1][1] = tri[1][1];
//	dp[2][1] = tri[1][1] + tri[2][1];
//	dp[2][2] = tri[1][1] + tri[2][2];
//	
//	dp[3][1] = dp[2][1] + tri[3][1];
//	dp[3][2] = max(dp[2][1] + tri[3][2], dp[2][2] + tri[3][2]);
//	dp[3][3] = dp[2][2] + tri[3][3];
//	
//	dp[4][1] = dp[3][1] + tri[4][1];
//	dp[4][2] = max(dp[3][1] + tri[4][2], dp[3][2] + tri[4][2]);
//	dp[4][3] = max(dp[3][2] + tri[4][3], dp[3][3] + tri[4][3]);
//	dp[4][4] = dp[3][3] + tri[4][4];

int n;
int tri[501][501];
int dp[501][501];

int main(){
	cin >> n;
	for(int i=1; i<=n;i++){
		for(int j=1; j<=i;j++){
			cin >> tri[i][j];
		}
	}
	dp[1][1] = tri[1][1];
	
	for(int i=2; i<=n; i++){
		for(int j = 1; j<=i; j++){
			if(j == 1){
				dp[i][j] = dp[i-1][j] + tri[i][j];
			}
			else if(j == i){
				dp[i][j] = dp[i-1][j-1] + tri[i][j];
			}
			else{
				dp[i][j] = max(dp[i-1][j-1] + tri[i][j], dp[i-1][j] + tri[i][j]);
			}
		}
	}
	
//	for(int i=1; i<=n;i++){
//		for(int j=1; j<=i;j++){
//			cout <<  dp[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	
	int rst = 0;
	for(int i=1; i<=n; i++){
		if(rst < dp[n][i]){
			rst = dp[n][i];
		}
	}
	cout << rst << '\n';
	return 0;
}
