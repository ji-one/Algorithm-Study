// 1747 소수&팰린드롬

#include <iostream>
#include <string>

using namespace std;

int n;
int a[2000001];

bool pen(int p) {
    string s = "";
    while(p>0) {
        char c = (p%10) + '0';
        s = c + s;
        p/=10;
    }
    int len = s.size()-1;
    for(int i=0; i<=len/2; i++) {
        if(s[i] != s[len-i])
            return false;
    }
    return true;
}
int main() {
    cin >> n;
    for(int i=2; i<=2000000; i++) {
        a[i] = i;
    }
    for(int i=2; i<=2000000; i++) {
        if(a[i] == 0) continue;
        for(int j=i+i; j<=2000000; j+=i) {
            a[j] = 0;
        }
    }

    for(int i=n; i<=2000000; i++) {
        if(a[i] == 0) continue;
        if(pen(i)) {
            cout << i;
            break;
        }
    }
    return 0;
}