// 2661 좋은 수열

#include <iostream>
#include <string>

using namespace std;

int n;
string s;

bool check(string a) {
    for(int i=0; i<a.size()-1; i++) { // 시작 
        int len = a.size() - i;
        if(len%2 == 1) continue;
        
        if(a.substr(i, len/2) == a.substr(i + len/2, len/2)) {
            return true;
        }
    }
    return false;
}
void solve(string a) {
    if(a.size() > 0 && check(a)) return ;
    if(s.size() > 0) return ;
    if(a.size() == n) {
        
        s = a;
        return ;
    }

    solve(a+"1");
    solve(a+"2");
    solve(a+"3");
}

int main() {
    cin >> n;
    solve("");
    cout << s;
    return 0;
}