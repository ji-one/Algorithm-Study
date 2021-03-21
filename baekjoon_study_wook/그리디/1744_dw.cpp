// 1744 수 묶기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int num[20001];
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    sort(num, num+n);

    int sum = 0;
    int ne_idx = 0;
    while(num[ne_idx] <= 0 && ne_idx<n){
        if(num[ne_idx+1] <= 0 && ne_idx+1 <n){
            sum += (num[ne_idx] * num[ne_idx+1]);
            ne_idx++;
        }
        else{
            sum += num[ne_idx];
        }
        ne_idx++;
    }
    int po_idx = n-1;
    while(num[po_idx] > 0 && po_idx >= 0){
        if(num[po_idx-1] > 1 && po_idx-1 >=0){
            sum += (num[po_idx] * num[po_idx-1]);
            po_idx--;
        }
        else{
            sum += (num[po_idx]);
        }
        po_idx--;

    }
    cout << sum;
    return 0;
}