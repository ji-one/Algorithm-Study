// 14501 ��� ---- �ַ�� ��  
#include <iostream> 

using namespace std;

int n;
int t[16];
int p[16];
int dp[16]; // dp[i+1] : i ���� ���� ���� �� 

/*
 d[i]�� i��° ���� ���� �� �ִ� �ִ� �ݾ�
 1) i��° ���� ���� ���� ���
 d[i+t[i]] = max(d[i+t[i]], d[i] + p[i]);

 2) i��° ���� ���� ���� �ʾ��� ���
 d[i+1] = max(d[i+1], d[i]);
*/ 
int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> t[i] >> p[i];
	}
	
	int rst = 0;
	for(int i=1; i<=n; i++){
		
		// 1) i��° ���� ���� ���� ���
		if(i+t[i] <= n+1){
			dp[i+t[i]] = max(dp[i+t[i]], dp[i] + p[i]);
			rst = max(rst, dp[i+t[i]]);
		}
		
		// 2) i��° ���� ���� ���� �ʾ��� ���
		dp[i+1] = max(dp[i+1], dp[i]);
		rst = max(rst, dp[i+1]); 
	}

	cout << rst;
	return 0;
}
