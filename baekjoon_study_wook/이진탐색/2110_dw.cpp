// 2110 공유기 설치
// 솔루션 봄

#include <iostream>
#include <algorithm>

using namespace std;

int n, c;
int pos[200001];
int rst;
void binarysearch(int start, int end){
    int left = start;
    int right = end;
    while(left<=right){
        int mid= (left+right)/2; // 공유기 사이 거리
        int num = 1;            // 공유기 설치 개수 -> 처음 위치에 설치
        int bpos = 0;           // 공유기 설치한 전 위치
        for(int cpos=1; cpos<n; cpos++){    //공유기 설치한 현 위치
            if(pos[cpos]-pos[bpos] >= mid){
                num++;
                bpos = cpos;
            }
        }
        if(num >= c){ // 공유기의 수를 줄이자 -> 거리를 늘려야한다
            left = mid+1;
            if(rst < mid){
                rst = mid;
            }
        }
        else{       // 공유기가 더 설치되어야한다-> 거리를 줄여야한다
            right = mid-1;
        }
        
    }
}
int main(){
    cin >> n >> c;
    for(int i=0; i<n; i++){
        cin >> pos[i];
    }
    sort(pos, pos+n);
    binarysearch(1, pos[n-1]);
    cout << rst;
    return 0;
}