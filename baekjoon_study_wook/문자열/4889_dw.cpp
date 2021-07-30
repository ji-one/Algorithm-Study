// 4889 안정적인 문자열

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int idx = 1;
    while(1) {
        cin >> s;
        if(s[0] == '-') break;

        int a =0;
        int cnt = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '{') {
                if(a == s.size()/2) {
                    cnt++;
                    a--;
                } else {
                    a++;
                }
            } else {
                if(a == 0 ) {
                    cnt++;
                    a++;
                } else {
                    a--;
                }
            }
        }

        cnt += a/2;
        cout << idx++ << ". " << cnt << '\n';
    }
    return 0;
}