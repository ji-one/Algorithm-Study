// 17427 약수의 합 2

#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    
    for(int i=1; i<=n; i++) {
        sum += (n/i)*i;
    }
    cout << sum;
    return 0;
}