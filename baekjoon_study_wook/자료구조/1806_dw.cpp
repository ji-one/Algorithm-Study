// 1806 부분합
// 투포인터
#include <iostream>
#include <algorithm>
using namespace std;

int n,s;
int arr[100001];
int main(){
    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int l =0, r=0;
    int tmp = 0;
    int rst=111111;
    while(l<=r){
        if(tmp >= s){
            rst = min(rst, r-l);
            tmp-=arr[l];
            l++;
        }
        else if(r == n)break;
        else{
            tmp+=arr[r];
            r++;
        }
    }
    if(rst == 111111) cout << 0;
    else    cout << rst;

    return 0;
}