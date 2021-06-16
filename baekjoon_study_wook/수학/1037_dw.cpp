// 1037 약수

#include<iostream>
#include<algorithm>
using namespace std;

int arr[51];
int main() {
    int c;
    cin >> c;
    for(int i=0; i<c; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+c);
    cout << arr[0] * arr[c-1];
    return 0;
}