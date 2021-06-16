// 17144 미세먼지 안녕!

#include <iostream>
#include <vector>

using namespace std;

int r,c,t;
int map[51][51];
vector<int> dust[51][51];
vector<int> air;    // [0] 위  [1] 아래

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
bool isInside(int x, int y){
    return x>=0 && y>=0 && x<r && y<c;
}
int main(){
    cin >> r >> c >> t;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int tmp;
            cin >> tmp;
            dust[i][j].push_back(tmp);
            if(tmp == -1)
                air.push_back(i);   // 공기 청정기 행 
        }
    }

    while(t--){
        
        // 미세먼지 확산
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(dust[i][j][0] > 0){ // 미세먼지가 있다면
                    int a = dust[i][j][0]/5;
                    int cnt = 0;
                    for(int k=0; k<4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(isInside(nx,ny) && dust[nx][ny][0] != -1){
                            cnt++;
                            dust[nx][ny].push_back(a);
                        }
                    }
                    dust[i][j][0] -= (cnt * a);
                }
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int n = dust[i][j].size();
                if(n > 1){
                    int sum = 0;
                    for(int k=0; k<n; k++){
                        sum+=dust[i][j][k];
                    }
                    dust[i][j].clear();
                    dust[i][j].push_back(sum);
                }
            }
        }
        // cout << "\n-------aaaaaaaa------\n";
        // for(int i=0; i<r; i++){
        //     for(int j=0; j<c; j++){
        //         cout << dust[i][j][0] << ' ';
        //     }
        //     cout << '\n';
        // }

        // 반시계 회전
        for(int i=air[0]-1; i>0; i--){
            dust[i][0][0] = dust[i-1][0][0];
        }

        for(int i=0; i<c-1; i++){
            dust[0][i][0] = dust[0][i+1][0];
        }

        for(int i=0; i<air[0]; i++){
            dust[i][c-1][0] = dust[i+1][c-1][0];
        }

        for(int i=c-1; i>1; i--){
            dust[air[0]][i][0] = dust[air[0]][i-1][0];
        }
        dust[air[0]][1][0] = 0;

        // 시계 회전
        for(int i=air[1]+1; i<r-1; i++){
            dust[i][0][0] = dust[i+1][0][0];
        }

        for(int i=0; i<c-1; i++){
            dust[r-1][i][0] = dust[r-1][i+1][0];
        }

        for(int i=r-1; i>air[1]; i--){
            dust[i][c-1][0] = dust[i-1][c-1][0];
        }

        for(int i=c-1; i>1; i--){
            dust[air[1]][i][0] = dust[air[1]][i-1][0];
        }
        dust[air[1]][1][0] = 0;

        // cout << "\n-----bbbbbbbbbbb-----\n";
        // for(int i=0; i<r; i++){
        //     for(int j=0; j<c; j++){
        //         cout << dust[i][j][0] << ' ';
        //     }
        //     cout << '\n';
        // }

    }

    int rst=0;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(dust[i][j][0] == -1) continue;
            rst += dust[i][j][0];
        }
    }
    cout << rst;
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<c; j++){
    //         cout << dust[i][j][0] << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}