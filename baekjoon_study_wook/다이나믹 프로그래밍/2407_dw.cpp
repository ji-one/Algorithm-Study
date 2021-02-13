// 2407 조합
// 솔루션 봄   -- 수가 long long 이상인 경우 스트링으로 변환
#include <iostream>
#include <string>
using namespace std;

int n,m;
string dp[101][101];

string string_add(string a, string b){
    string rst = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while(i>=0 && j>=0){
        int tmp = (a[i--] - '0') + (b[j--] - '0') + carry;
        rst = to_string(tmp%10) + rst;
        carry = tmp/10;
    }

    while(i>=0){
        int tmp = a[i--] - '0' + carry;
        rst = to_string(tmp%10) + rst;
        carry = tmp/10;
    }

    while (j>=0)
    {
        int tmp = b[j--] - '0' + carry;
        rst = to_string(tmp%10) +rst;
        carry = tmp/10;
    }
    
    if(carry)

        rst = to_string(carry) + rst;
    return rst;
}
int main(){
    cin >> n >>m;
    dp[0][0] = "1";
    for(int i=1; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j==0) dp[i][j] = "1";
            else     dp[i][j] = string_add(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    cout << dp[n][m];
    return 0;
}