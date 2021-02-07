// 2011 암호코드
/*  솔루션 봄
    1. dp[a] = dp[a-1] + dp[a] -- 숫자 한자리씩 끊어서 알파벳을 얻는 경우
        조건 : dp[a] 는 1~9 숫자여야 된다
    2. dp[a] = dp[a-2] + dp[a] -- 숫자 두자리를 이용해서 알파벳을 얻는 경우
        조건 : dp[a] 는 첫번째 수가 아니고, 두자리수가 10~26
*/
#include <iostream>
#include <string>
using namespace std;

string str;
int arr[5001];
int dp[5001]; // dp[a]=b a번째까지 만들 수 있는 암호 수는 b
int main(){
    cin >> str;
    int n = str.size();
    for(int i=0; i<n; i++){
        arr[i+1] = str[i]-'0';
    }

    dp[0] = 1;
    for(int i=1; i<=n; i++){
        if(arr[i]>=1 && arr[i]<=9){
            dp[i] += dp[i-1];
            dp[i]%=1000000;
        }
        int tmp = (arr[i-1]*10 + arr[i]);
        if(i !=0 && tmp >=10 && tmp <=26){
            dp[i] += dp[i-2];
            dp[i]%=1000000;
        }
        
    }

    cout << dp[n];

    return 0;
}