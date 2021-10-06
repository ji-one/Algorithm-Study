// 2559 수열

#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int main() {
    int n,k, l=0, r=0, sum=0, rst=0;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<k; i++) {
        sum+=arr[r++];
    }
    rst = sum;
    while(r<n) {
        sum -= arr[l++];
        sum += arr[r++];
        rst = max(rst, sum);
    }
    cout << rst;
    return 0;
}