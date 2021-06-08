// 12904 A와 B

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s,t;

int main() {
    cin >> s >> t;

    while(s.size() < t.size()) {
        string tmp = "";
        if(t[t.size()-1] == 'B') {
            tmp = t.substr(0, t.size()-1);
            reverse(tmp.begin(), tmp.end());
        } else {
            tmp = t.substr(0, t.size()-1);
        }
        t = tmp;
    }
    if(t==s){
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}