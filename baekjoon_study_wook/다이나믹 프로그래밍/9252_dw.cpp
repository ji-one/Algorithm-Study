// 9252 LCS 2

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

string a, b;
int dp[1001][1001];
int main() {
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int len = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i-1] == b[j-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
            len = max(len, dp[i][j]);
        }
    }
    cout << len << '\n';
    stack<char> st;
    for(int i=n; i>0; i--) {
        for(int j=m; j>0; j--) {
            if(dp[i][j] == len && dp[i-1][j] == (len-1) && dp[i][j-1] == (len-1)) {
                st.push(a[i-1]);
                len--;
                break;
            }
        }
    }

    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    // cout <<'\n';
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m;j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout <<'\n';
    // }
    return 0;
}