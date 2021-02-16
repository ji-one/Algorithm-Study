/*
    플로이드 와샬
    솔루션 봄
    a가 b 이김 -> b가 c 이김 -> a가 c 이김
    => 모든 승패를 확인하면서 승패를 지을 수 있는 지 검사.
*/
#include <string>
#include <vector>


using namespace std;

int win[101][101];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0; i<results.size(); i++){
        win[results[i][0]][results[i][1]]++;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(win[i][k] && win[k][j]){
                    win[i][j]++;
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        int count = 0;
        for(int j=1; j<=n; j++){
            // i가 j를 이겼거나 j가 i를 이겼으면 승패결과를 알 수 있음
            if(win[i][j] || win[j][i]) 
                count++;
        }
        if(count == n-1) // 자신을 제외한 모든 사람과 승패결과를 확인 할 수 있다.
            answer++;
    }
    return answer;
}