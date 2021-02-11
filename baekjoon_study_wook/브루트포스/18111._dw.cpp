//18111 마인크래프트

#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int n,m,b;
int map[511][511];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> b;
    int maxh=0;
    int minh=300;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] > maxh) maxh = map[i][j];
            if(map[i][j] < minh) minh = map[i][j];
        }
    }

    int rst = INT_MAX;
    int ans = 0;
    for(int h=minh; h<=maxh; h++){
        int time = 0;

        int remove_b=0;
        int build_b=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int tmp = h - map[i][j];
                if(tmp > 0 ){   // 쌓아야하는 개수만큼 센다
                    build_b += tmp;
                }
                if(tmp <0){     // 제거해야하는 개수만큼 센다
                    remove_b+= (tmp*-1);
                }
            }
        }

        if(build_b > remove_b + b) continue; // 쌓을 수 없으면 종료
        time += build_b;        // 쌓아야하는 수만큼 시간 증가
        time += (remove_b*2);   // 제거해야하는 수만큼 시간 증가

        if(rst >= time){        // 시간 비교
            rst = time;
            ans = max(ans, h);
        }
 
    }
    
    printf("%d %d", rst, ans);
    return 0;
}