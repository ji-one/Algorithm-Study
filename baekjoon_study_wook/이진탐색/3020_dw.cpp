// 3020 개똥벌레

#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;

int h1[111111];
int h2[111111];
int n, h;

int lowerBound(int start, int end, int target) {
    int low = start;
    int high = end;
    while(low < high) {
        int mid = (low + high)/2;
        if(h1[mid] >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

int upperBound(int start, int end, int target) {
    int low = start;
    int high = end;
    while(low < high) {
        int mid = (low + high)/2;
        if(h2[mid] > target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

int main() {
    cin >> n >> h;
    for(int i=0; i<n/2; i++) {
        int suck, jong;
        cin >> suck >> jong;
        h1[i] = suck;
        h2[i] = jong;
    }

    sort(h1, h1+n/2);
    sort(h2, h2+n/2);

    int answer = MAX;
    int cnt = 0;
    for(int i=1; i<=h; i++) {
        int j = (n/2 - lowerBound(0, n/2, i));
        j +=  (n/2 - upperBound(0, n/2, h - i));
        if(answer > j) {
            answer = j;
            cnt = 1;
        } else if(answer == j){
            cnt++;
        }
    }
    cout << answer << ' ' << cnt;
    return 0;
}