// 1699 �������� �� 
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int dp[100001];
int main(){
	cin >> n;
	
	for(int i = 1;i <=n; i++){
		
		int sqr = sqrt(i);
		int p = sqr * sqr;
		dp[i] = 1 + dp[i-p];
		
		for(int j=sqr-1 ; j>=1; j--){
			
			int p = j*j;
			dp[i] = min(1 + dp[i-p], dp[i]);
		
		}
		
	}
	cout << dp[n];
	return 0;
}
