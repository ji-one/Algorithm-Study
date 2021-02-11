// 17219 비밀번호 찾기
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, string> um;

int n,m; 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string ad;
        string pa;
        cin >> ad >> pa;
        um[ad] = pa;
    }
    for(int i=0; i<m; i++){
        string ad;
        cin >> ad;
        cout << um[ad] << '\n';
    }
    return 0;
}