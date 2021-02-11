// 5525 IOIOI
// 솔루션 봄
#include <iostream>
#include <string>
using namespace std;

int n,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;

    cin >> n >> m >> s;
    
    int cnt=0;  // 패턴 횟수
    int rst=0;
    for(int i=0; i<m-2; i++){
        if(s[i] == 'I' && s[i+1] =='O' & s[i+2] == 'I'){
            cnt++;
            if(cnt == n){ // Pn 이 같다면 카운트
                rst++;
                cnt--;      // i번째는 셈하므로 빼기
            }
            i++;
        }
        else{   // 규칙에 어긋나므로 초기화
            cnt=0;
        }
    }
    cout << rst;
    return 0;
}