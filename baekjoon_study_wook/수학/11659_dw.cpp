// 11659 구간 합 구하기 4

#include <iostream>

using namespace std;

int n,m;
int a[100001];
int sum[100001];

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    
    cin>> n>> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    
    
    while(m--) {
        int i,j;
        cin >> i >> j;
        cout << sum[j] - sum[i-1] <<'\n';
    }
    return 0;
}