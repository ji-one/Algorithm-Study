#include <string>
#include <iostream>
using namespace std;

int visit[12][12][4];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int solution(string dirs) {
    int answer = 0;
    int x = 5;
    int y = 5;
    int d = 0;
    for(int i=0; i<dirs.size(); i++){
        int nx = x;
        int ny = y;
        if(dirs[i] == 'U'){
            nx += dx[0]; 
            ny += dy[0];
            d=0;
        }
        else if(dirs[i] == 'L'){
            nx += dx[1]; 
            ny += dy[1];
            d=1;
        }
        else if(dirs[i] == 'D'){
            nx += dx[2]; 
            ny += dy[2];
            d=2;
        }
        else if(dirs[i] == 'R'){
            nx += dx[3]; 
            ny += dy[3];
            d=3;
        }
        if(nx>=0 && nx<11 && ny>=0 && ny<11){
            if(!visit[nx][ny][d]){
                answer++;
                visit[nx][ny][d] = 1;
                visit[x][y][(d+2)%4] = 1;
            }
            x = nx;
            y = ny;
        }
        
    }
    return answer;
}