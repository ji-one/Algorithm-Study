// 11399 ATM

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int w[1001];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> w[i];
    }
    sort(w, w+n);
    int sum = 0;
    int rst = 0;
    for(int i=0; i<n; i++){
        sum += w[i];
        rst += sum;
    }
    cout << rst;
    return 0;
}