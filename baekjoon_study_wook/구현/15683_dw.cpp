// 15683 감시
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n,m;

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
bool isInside(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
vector<pair<int, pair<int, int>>> v;    // {cctv, {x,y}}
int rst = 100;

void dfs(int cnt, int x, int map[9][9]){
    if(cnt == v.size()){
        int blind_spot = 0;
        // cout << '\n';
       
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // cout << map[i][j] << ' ';
                if(map[i][j] == 0)
                    blind_spot++;
            }
            // cout << '\n';
        }
        rst = min(rst, blind_spot);
        return ;
    }

    int tmp[9][9];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tmp[i][j] = map[i][j];
        }
    }
    for(int i=x; i<v.size(); i++){
        int cx = v[i].second.first;
        int cy = v[i].second.second;
        if(v[i].first == 1){
            for(int j=0; j<4; j++){
                int nx = cx + dx[j];
                int ny = cy + dy[j];
                while(isInside(nx,ny)){
                    if(map[nx][ny] == 6) break;
                    if(map[nx][ny] == 0) map[nx][ny] = 9;
                    nx += dx[j];
                    ny += dy[j];
                }
                dfs(cnt+1, i+1, map);
                
                // 복구
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        map[i][j] = tmp[i][j];
                    }
                }
            }
        }
        if(v[i].first == 2){
            for(int j=0; j<2; j++){
                int nxa = cx + dx[j];
                int nya = cy + dy[j];
                while(isInside(nxa,nya)){
                    if(map[nxa][nya] == 6) break;
                    if(map[nxa][nya] == 0) map[nxa][nya] = 9;
                    nxa += dx[j];
                    nya += dy[j];
                }

                int nxb = cx + dx[j+2];
                int nyb = cy + dy[j+2];
                while(isInside(nxb,nyb)){
                    if(map[nxb][nyb] == 6) break;
                    if(map[nxb][nyb] == 0) map[nxb][nyb] = 9;
                    nxb += dx[j+2];
                    nyb += dy[j+2];
                }

                dfs(cnt+1, i+1, map);

                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        map[i][j] = tmp[i][j];
                    }
                }
            }
        }


        if(v[i].first == 3){
            // 90도 회전
            for(int j=0; j<4; j++){
                int nxa = cx+dx[j%4];
                int nya = cy+dy[j%4];
                while(isInside(nxa,nya)){
                    if(map[nxa][nya] == 6) break;
                    if(map[nxa][nya] == 0) map[nxa][nya] = 9;
                    nxa += dx[j%4];
                    nya += dy[j%4];
                }

                int nxb = cx+dx[(j+1)%4];
                int nyb = cy+dy[(j+1)%4];
                while(isInside(nxb,nyb)){
                    if(map[nxb][nyb] == 6) break;
                    if(map[nxb][nyb] == 0) map[nxb][nyb] = 9;
                    nxb += dx[(j+1)%4];
                    nyb += dy[(j+1)%4];
                }

                dfs(cnt+1, i+1, map);
                // 복구
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        map[i][j] = tmp[i][j];
                    }
                }
            }
        }


        if(v[i].first == 4){
            // 90도 회전
            for(int j=0; j<4; j++){
                int nxa = cx+dx[j%4];
                int nya = cy+dy[j%4];
                while(isInside(nxa,nya)){
                    if(map[nxa][nya] == 6) break;
                    if(map[nxa][nya] == 0) map[nxa][nya] = 9;
                    nxa += dx[j%4];
                    nya += dy[j%4];
                }

                int nxb = cx+dx[(j+1)%4];
                int nyb = cy+dy[(j+1)%4];
                while(isInside(nxb,nyb)){
                    if(map[nxb][nyb] == 6) break;
                    if(map[nxb][nyb] == 0) map[nxb][nyb] = 9;
                    nxb += dx[(j+1)%4];
                    nyb += dy[(j+1)%4];
                }

                int nxc = cx+dx[(j+2)%4];
                int nyc = cy+dy[(j+2)%4];
                while(isInside(nxc,nyc)){
                    if(map[nxc][nyc] == 6) break;
                    if(map[nxc][nyc] == 0) map[nxc][nyc] = 9;
                    nxc += dx[(j+2)%4];
                    nyc += dy[(j+2)%4];
                }

                dfs(cnt+1, i+1, map);
                // 복구
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        map[i][j] = tmp[i][j];
                    }
                }
            }
        }


        if(v[i].first == 5){
            for(int j=0; j<4; j++){
                int nx = cx + dx[j];
                int ny = cy + dy[j];
                while(isInside(nx,ny)){
                    if(map[nx][ny] == 6) break;
                    if(map[nx][ny] == 0) map[nx][ny] = 9;
                    nx += dx[j];
                    ny += dy[j];
                }
            }
            dfs(cnt+1, i+1, map);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    map[i][j] = tmp[i][j];
                }
            }
        }
    }
}
int main(){
    int map[9][9];
    memset(map,0,sizeof(map));
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] >= 1 && map[i][j] <=5){
                v.push_back({map[i][j],{i,j}});
            }
        }
    }
    dfs(0,0,map);
    cout << rst;
    return 0;
}