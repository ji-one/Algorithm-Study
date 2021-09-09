// 1174 줄어드는 숫자

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, answer;
vector<long long> v; 
void dfs(string s) {
    if(s.size() > 0) {
        v.push_back(stoll(s));
    }

    for(int i=0; i<10; i++) {
        if(s.size() == 0 || (s.back()-'0') > i) {
            dfs(s + char(i+'0'));
        }
    }
}

int main() {
    cin >> n;
    
    dfs("");
    sort(v.begin(), v.end());
    if(v.size() < n) {
        cout << -1;
    } else {
        cout << v[n-1];
    }
    return 0;
}