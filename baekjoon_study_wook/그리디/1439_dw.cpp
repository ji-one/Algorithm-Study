// 1439 뒤집기

#include <iostream>
#include <string>

using namespace std;

string s;
int main() {
    cin >> s;
    int zcnt = 0;
    for(int i=0; i<s.size(); i++) {
        if(i==0 && s[i] == '0') {
            zcnt++;
        } else if(s[i] == '0' && s[i-1] == '1') {
            zcnt++;
        }
    }

    int ocnt = 0;
    for(int i=0; i<s.size(); i++) {
        if(i==0 && s[i] == '1') {
            ocnt++;
        } else if(s[i] == '1' && s[i-1] == '0') {
            ocnt++;
        }
    }
    cout << (ocnt < zcnt ? ocnt : zcnt) << '\n';

    return 0;
}