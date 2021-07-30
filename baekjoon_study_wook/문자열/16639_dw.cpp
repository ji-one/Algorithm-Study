// 16639 괄호 추가하기 3

#include <iostream>
#include <string>
#include <vector>
#define MIN -1999999999

using namespace std;


int n, ans = MIN;
string s;
bool check[20];
vector<int> v;
int num[20];
int copyNum[20];
char op[20];

int cal() {
    copy(num, num+n, copyNum);
    
    // cout << "----------------\n" ;
    for(int i=0; i<n/2; i++) {
        int temp = 1;
        while(copyNum[v[i]+temp] == MIN) {
            temp++;
        }

        if(op[v[i]] == '+') {
            copyNum[v[i]+temp] = copyNum[v[i]] + copyNum[v[i]+temp];
            copyNum[v[i]] = MIN;
        }
        if(op[v[i]] == '-') {
            copyNum[v[i]+temp] = copyNum[v[i]] - copyNum[v[i]+temp];
            copyNum[v[i]] = MIN;
        }
        if(op[v[i]] == '*') {
            copyNum[v[i]+temp] = copyNum[v[i]] * copyNum[v[i]+temp];
            copyNum[v[i]] = MIN;
        }

        // for(int j=0; j<=n/2; j++) {
        //     cout << copyNum[j] << ' ';
        // }
        // cout << '\n';
    }
    // cout << "\n----------------\n" ;
    return copyNum[n/2];
}

void dfs(int cnt) {
    if(cnt == n/2) {
        int rst = cal();
        if(rst > ans) {
            ans = rst;
        }
        // cout << rst << '\n';
        return ;
    }

    for(int i=0; i<n/2; i++) {
        if(check[i]) continue;
        check[i] = 1;
        v.push_back(i);
        dfs(cnt+1);
        v.pop_back();
        check[i] = 0;
    }
}
int main(){
    cin >> n >> s;
    
    for(int i=0; i<n; i+=2) {
        num[i/2] = s[i]-'0';
    }
    for(int i=1; i<n; i+=2) {
        op[i/2] = s[i];
    }
    dfs(0);
    cout << ans;
    return 0;
}