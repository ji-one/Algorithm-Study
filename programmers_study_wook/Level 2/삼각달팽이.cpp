#include <string>
#include <vector>
#include <iostream>
using namespace std;

int tri[1001][1001];
vector<int> solution(int n) {
    vector<int> answer;
    int num = 1;
    int r=-1, c=0;
    
    for(int i=0; i<n; i++){
        int cnt = n-i;
        if(i%3 == 0){   // 아래
            while(cnt--){
                
                tri[++r][c] = num++;
            }
        }
        if(i%3 == 1){   // 오른
            while(cnt--){
                tri[r][++c] = num++;
            }
        }
        if(i%3 == 2){   // 위
            while(cnt--){
                tri[--r][--c] = num++;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            answer.push_back(tri[i][j]);
        }
    }
    return answer;
}