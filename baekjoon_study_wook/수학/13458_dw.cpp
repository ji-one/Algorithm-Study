// 13458 시험 감독

#include<iostream>

using namespace std;

long long n, b, c, rst;
long long a[1000001];
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cin >> b >> c;
    rst = n;
    for(int i=0; i<n; i++) {
        a[i] -= b;
        if(a[i] > 0) {
            rst = rst + (a[i]/c);
            if(a[i]%c != 0) {
                rst++;
            }
        }
        
        
    }
    cout <<rst;
    return 0;
}