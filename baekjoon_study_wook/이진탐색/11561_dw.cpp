// 11561 징검다리

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long n;

long long binarySearch() {
    long long left = 0;
    long long right = 1000000000;
    long long answer=0;

    while(left <= right) {
        long long mid = (left+right)/2;
        long long sum = mid*(mid+1)/2;

        if(sum > n) {
            right = mid - 1;
        } else {
            left = mid + 1;
            answer = max(mid, answer);
        }
    }

    return answer;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << binarySearch() << '\n';
    }

    return 0;
}