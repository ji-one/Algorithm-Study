// 2096 내려가기
/* 솔루션 봄
  슬라이딩 윈도우 알고리즘
  이전 정보만을 알고 있으면 되므로 
  필요 없는 정보까지 배열에 저장할 필요 없다
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int MAX[3];     // 전 행의 최대값들
int MIN[3];     // 전 행의 최소값들
int maxtmp[3];  // 현재 행의 최대값들
int mintmp[3];  // 현재 행의 최소값들
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin >> maxtmp[j];
            mintmp[j] = maxtmp[j];
            if(j!=1){
                maxtmp[j] += max(MAX[j], MAX[1]);
                mintmp[j] += min(MIN[j], MIN[1]);
            }
            else{
                maxtmp[j] += max(MAX[j], max(MAX[0], MAX[2]));
                mintmp[j] += min(MIN[j], min(MIN[0], MIN[2]));
            }
        }
        memcpy(MAX, maxtmp, sizeof(MAX));
        memcpy(MIN, mintmp, sizeof(MIN));
    
    }
    
    sort(MAX, MAX+3);
    sort(MIN, MIN+3);
    cout << MAX[2] << ' ' << MIN[0];
    return 0;
}