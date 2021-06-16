// 13458 시험 감독

#include<iostream>

using namespace std;

int n, b, c, rst;
int a[1000001];
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cin >> b >> c;
    rst = n;
    for(int i=0; i<n; i++) {
        a[i] -= b;
        rst = rst + (a[i]/c);
        if(a[i]%c != 0) {
            rst++;
        }
        
    }
    cout <<rst;
    return 0;
}