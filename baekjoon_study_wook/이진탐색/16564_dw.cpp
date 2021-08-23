// 16564 히오스 프로게이머

#include <iostream>
#include <algorithm>

using namespace std;

long long n,k, t;
long long x[1000001];

void binarySearch(int start, int end) {
    long long left = start;
    long long right = end;
    while(left <= right) {
        // mid = 팀 목표 레벨
        long long mid = (left + right)/2;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            if(x[i] < mid) {
                sum += (mid - x[i]);
            }
        }
        if(sum <= k) {
            left = mid + 1;
            t = mid;
        } else {
            right = mid - 1;
        }
    }
}
int main() {
    cin >> n >> k;
    long long maxLevel=0;
    for(int i=0; i<n; i++) {
        cin >> x[i];
        if(maxLevel < x[i]) {
            maxLevel = x[i];
        }
    }
    binarySearch(0, maxLevel + k);
    cout << t;
    return 0;
}