//11057 오르막 수 
#include <iostream>

using namespace std;

int n;
int arr[1001][11];
int dp[1001];
int main(){
	cin >> n;
	
	for(int i=1; i<=10;i++){
		arr[1][i] = 1;
		dp[1] += arr[1][i];
	}
//	int tmp = dp[0];
//	for(int i=0; i<10; i++){
//		
//		arr[1][i+1] = tmp - arr[0][i];
//		tmp -= arr[0][i];
//		dp[1] += arr[1][i+1];
//		cout << arr[1][i+1] << ' '; 
//	}
//	cout << '\n';
//	
//	tmp = dp[1];
//	for(int i=0; i<10; i++){
//		
//		arr[2][i+1] = tmp - arr[1][i];
//		tmp -= arr[1][i];
//		dp[2] += arr[2][i+1];
//		cout << arr[2][i+1] << ' '; 
//	}
	
	for(int i=2; i<=n; i++){
		int tmp = dp[i-1];
		for(int j=0; j<10; j++){
			
			arr[i][j+1] = (tmp - arr[i-1][j])%10007;
			tmp -= arr[i-1][j];
			dp[i] += (arr[i][j+1])%10007;
		}
	}
	
	
	cout << dp[n]%10007;
	return 0;
}
