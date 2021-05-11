// 2343 기타 레슨
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int len[100001];
int rst = 987654321;
void binarySearch(int start, int end){
    int left = start;
    int right = end;
    while(left<=right){
        int mid = (left+right)/2;
        int cnt = 0;
        int temp=0;
        bool isPo = true;
        for(int i=0; i<n; i++){
            if(len[i] > mid){   // 곡 하나가 녹음 최대시간 보다 길 수 없다.
                isPo = false;
                break;
            }
            if(temp+len[i] <= mid){
                temp+=len[i];
            }
            else{
                cnt++;
                temp = len[i];
            }
            if(i == n-1){   // 마지막 블루레이 개수 포함
                cnt++;
            }
        }
        if(!isPo){
            left = mid + 1;
        }
        else{
            if(cnt <= m){   // m 개로 만들 수 있는 지 확인
                rst = min(rst, mid);
                right = mid - 1;
            }
            else if(cnt > m){
                left = mid + 1;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> len[i];
        sum += len[i];
    }
    binarySearch(0,sum);
    cout << rst;
    return 0;
}