// 2670 연속부분 최대곱
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
double arr[10001];
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    double maxValue = 0;
    for(int i=0; i<n; i++){
        double tmp = 1;
        
        for(int j=i; j<n; j++){
            tmp *= arr[j];
            maxValue = max(maxValue, tmp);
        }
    }
    // cout << (maxValue*1000) / 1000;
    printf("%.3lf", maxValue);
    return 0;
}