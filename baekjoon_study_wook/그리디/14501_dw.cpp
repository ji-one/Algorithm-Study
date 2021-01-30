// 14501 퇴사 ---- 솔루션 봄  
#include <iostream> 

using namespace std;

int n;
int t[16];
int p[16];
int dp[16]; // dp[i+1] : i 까지 일한 받을 돈 

/*
 d[i]는 i번째 날에 받을 수 있는 최대 금액
 1) i번째 날에 일을 했을 경우
 d[i+t[i]] = max(d[i+t[i]], d[i] + p[i]);

 2) i번째 날에 일을 하지 않았을 경우
 d[i+1] = max(d[i+1], d[i]);
*/ 
int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> t[i] >> p[i];
	}
	
	int rst = 0;
	for(int i=1; i<=n; i++){
		
		// 1) i번째 날에 일을 했을 경우
		if(i+t[i] <= n+1){
			dp[i+t[i]] = max(dp[i+t[i]], dp[i] + p[i]);
			rst = max(rst, dp[i+t[i]]);
		}
		
		// 2) i번째 날에 일을 하지 않았을 경우
		dp[i+1] = max(dp[i+1], dp[i]);
		rst = max(rst, dp[i+1]); 
	}

	cout << rst;
	return 0;
}
