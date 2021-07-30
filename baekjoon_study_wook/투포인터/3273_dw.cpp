// 3273 두 수의 합

#include <iostream>
#include <algorithm>

using namespace std;

int n, x;
int arr[100001];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    sort(arr, arr+n);
    int left=0, right = n-1;
    int pairCnt = 0;
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == x) {
            pairCnt++;
            left++;
            right--;
        } else if(sum < x) {
            left++;
        } else {
            right--;
        }

    }
    cout << pairCnt;
    return 0;
}