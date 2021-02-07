// 1789 수들의 합
#include <iostream>

using namespace std;

long long s, n;
void binarySearch(long long start, long long end){
    long long left = start;
    long long right = end;
    while(left<=right){
        long long mid = (left + right)/2;
        long long k = mid * (mid+1) / 2;
        if (k > end)
        {
            right = mid - 1;
        }
        else{
            left = mid + 1;
            n = mid;
        }
        
    }

}
int main(){
    cin >> s;
    binarySearch(0, s);
    cout << n;
    return 0;
}