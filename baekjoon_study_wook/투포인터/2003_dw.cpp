// 2003 수들의 합 2

#include <iostream>

using namespace std;

int n,m;
int a[10001];

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int sum = 0;
    int left=0, right = 0;
    int rst = 0;

    while(left<=right) {
        if(sum >= m) {
            if(sum == m) {
                rst++;
            }
            sum -= a[left];
            left++;
        } else {
            if(right == n+1) break;
            sum += a[right];
            right++;
        }
    }
    cout << rst;
    return 0;
}