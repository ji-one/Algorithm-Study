// 1062 가르침

#include <iostream>
#include <string>

using namespace std;

int n,k, ans;
int alpha[26]; // a b c d e f g h i j k l m n o p q r s t u v w x y z
string s[51];

void dfs(int cnt, int idx) {
    if(cnt == k) {  // 가르친 개수
        int res = 0;
        for(int i=0; i<n; i++) {
            bool pass = true;
            for(int j=0; j<s[i].size(); j++) {
                if(alpha[s[i][j] - 'a'] == 0) {
                    pass = false;
                    break;
                }
            }
            if(pass) {
                res++;
            }
        }
        if(res > ans) {
            ans = res;
        }
        return ;
    }

    for(int i=idx; i<26; i++) {
        if(alpha[i] == 1) continue;
        alpha[i] = 1;
        dfs(cnt+1, i);
        alpha[i] = 0;
    } 
}
int main() {
    cin >> n >> k;
    alpha['a' - 'a'] = 1;
    alpha['n' - 'a'] = 1;
    alpha['t' - 'a'] = 1;
    alpha['i' - 'a'] = 1;
    alpha['c' - 'a'] = 1;
    
    for(int i=0 ;i<n; i++) {
        cin >> s[i];
    }

    if(k < 5) {
        cout << 0 << '\n';
        return 0;
    }

    dfs(5, 0);

    cout << ans;
    return 0;
}