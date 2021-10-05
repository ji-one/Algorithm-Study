// 2230 수 고르기

#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int a[100001];
int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int l=0,r=0;
    int rst=2000000001;
    while(l<=r) {
        
        int diff = a[r] - a[l];
        if(r == n-1) {
            if(diff < m) {
                break;
            } else {
                if(rst > diff) {
                    rst = diff;
                }
                l++;
            }
        } else {
            if(diff >= m) {
                if(rst > diff) {
                    rst = diff;
                }
                l++;
            } else {
                r++;
            }
        }

        
    }
    cout << rst;
    return 0;
}