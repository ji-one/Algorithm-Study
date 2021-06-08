// 14426 접두사 찾기

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,m;
string s[10001];

bool binary(string str) {
    int left = 0, right = n;
    int len = str.size();
    while(left <= right) {
        int mid = (left + right)/2;
        if(str < s[mid].substr(0,len)) {
            right = mid -1;
        } else if( str > s[mid].substr(0,len)) {
            left = mid + 1;
        } else {
            return true;
        }

    }

    return false;
}
int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> s[i];
    }
    sort(s, s+n);
    int cnt = 0;
    for(int i=0; i<m; i++) {
        string tmp = "";
        cin >> tmp;
        if(binary(tmp)) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}