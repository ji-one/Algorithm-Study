// 1431 시리얼 번호

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string serial[1001];

bool cmp(string a, string b) {
    if(a.size() == b.size()) {
        int aNum = 0, bNum = 0;
        for(int i=0; i<a.size(); i++) {
            if(a[i] >= '0' && a[i] <= '9') {
                aNum+=(a[i] - '0');
            }
            if(b[i] >= '0' && b[i] <= '9') {
                bNum+=(b[i] - '0');
            }
        }
        if(aNum == bNum) {
            return a<b;
        }

        return aNum < bNum;
    }

    return a.size() < b.size();
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> serial[i];
    }
    sort(serial, serial + n, cmp);
    
    for(int i=0; i<n; i++) {
        cout << serial[i] <<'\n';
    }
    return 0;
}