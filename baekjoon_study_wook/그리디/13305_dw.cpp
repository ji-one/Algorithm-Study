// 13305 주유소

#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long road[100001];
long long oil[100001];
int main(){
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> road[i];
    }
    for(int i=0; i<n; i++){
        cin >> oil[i];
    }
    long long rst = oil[0] * road[0];
    long long tmp = oil[0];
    for(int i=1; i<n-1; i++){
        // 기름 값이 작은 것을 선택
        tmp = min(tmp, oil[i]);
        rst += tmp*road[i];
    }
    cout << rst;
    return 0;
}