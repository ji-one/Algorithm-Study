// 1654 랜선 자르기
#include <iostream>
#include <algorithm>
using namespace std;

int k,n;
long long line[10001];
long long rst;

void binary_search(long long start, long long end){
    long long left = start;
    long long right = end;
    while(left<=right){
        long long mid = (left + right)/2;
        long long cnt = 0;
        for(int i=0; i<k; i++){
            cnt += (line[i]/mid);
        }
        if(n <= cnt){
            rst = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
}
int main(){
    cin >> k >> n;
    long long max_value = 0;
    for(int i=0; i<k; i++){
        cin >> line[i];
        max_value = max(max_value, line[i]);
    }
    binary_search(1,max_value);
    cout << rst;
    return 0;
}