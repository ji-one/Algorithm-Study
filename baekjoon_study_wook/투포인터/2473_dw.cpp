// 2473 세 용액

#include <iostream>
#include <algorithm>
#define MAX 3000000001

using namespace std;

long long arr[5000];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    long long sum = MAX;
    int a, b, c;
    for(int i=0; i<n-2; i++) {
        int left = i+1;
        int right = n-1;
        // -97 -6 -2 6 98
        while(left < right) {
            long long tmp = arr[i] + arr[left] + arr[right];
            if(sum > abs(tmp)) {
                a = arr[i];
                b = arr[left];
                c = arr[right];
                sum = abs(tmp);
            }
            if(tmp < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << a << ' ' << b << ' ' << c; 
    return 0;
}