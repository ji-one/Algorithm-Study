// 1644 소수의 연속합

#include <iostream>

using namespace std;

int n;
int a[4000001];

int main() {
    cin >> n;
    for(int i=2; i<=4000000; i++) {
        a[i] = i;
    }
    for(int i=2; i<=4000000; i++) {
        if(i==0) continue;
        for(int j=i+i; j<=4000000; j+=i) {
            a[j] = 0;
        }
    }

    int sum = 0;
    int left = 2, right = 2;
    int rst = 0;
    while(left <= right) {
        if(sum >= n) {
            if(sum == n) {
                rst++;
            }
            sum -= a[left];
            left++;
            while(a[left] == 0) {
                left++;
            }
        } else {
            if(right > n) break;
            sum += a[right];
            right++;
            while(a[right] == 0) {
                right++;
            }
        }
        // cout << sum << ' ';
    }
    cout << rst;
    return 0;
}