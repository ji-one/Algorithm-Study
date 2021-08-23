// 2212 센서
// 솔루션 참고

#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int a[10001];
int dist[10000];

int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);
    for(int i=0; i<n-1; i++) {
        dist[i] = a[i+1] - a[i];
    }

    sort(dist, dist + n - 1);

    int rst = 0;
    for(int i=0; i<n-k; i++) {
        rst += dist[i];
    }
    cout << rst;

    return 0;
}