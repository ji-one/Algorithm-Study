// 3079 입국심사

#include <iostream>

using namespace std;

long long n,m, answer;
int t[100001];

void binarySearch(long long start, long long end) {
    long long left = start;
    long long right = end;
    while(left <= right) {
        long long mid = (left+right)/2;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            sum+=(mid/t[i]);
        }
        if(sum >= m) {
            answer = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
}
int main() {
    cin >> n >> m;
    long long maxTime = 0;
    for(int i=0; i<n; i++) {
        cin >> t[i];
        if(maxTime < t[i]) {
            maxTime = t[i];
        }
    }

    binarySearch(0, maxTime*m);
    cout << answer ;
    return 0;
}