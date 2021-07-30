// 2638 치즈

#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int cheeze[101][101];
// int melt[101][101];
map<pair<int,int>, int> melt;
int visit[101][101];
int n,m;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool isInside(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

bool bfs() {

    queue<pair<int, int>> q;
    q.push({0,0});
    visit[0][0] = 1;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx,ny) && !visit[nx][ny] && cheeze[nx][ny] == 0) {
                visit[nx][ny] = 1;
                q.push({nx,ny});
            } else if (isInside(nx,ny) && cheeze[nx][ny] == 1) {
                melt[{nx,ny}]++;
            }
        }
    }

    if(melt.size() > 0) {
        return 0;
    }
    return 1;
}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> cheeze[i][j];
        }
    }

    int t = 0;
    while(1) {
        bool exit = bfs();
        if(exit) {
            break;
        }
        map<pair<int,int>, int>::iterator it;
        for(it=melt.begin(); it!=melt.end(); it++) {
            if(it->second >= 2) {
                int x = it->first.first;
                int y = it->first.second;
                cheeze[x][y] = 0;
            }
        }
        
        fill(&visit[0][0], &visit[n-1][m], 0);
        
        melt.clear();
        t++;
    }

    cout << t;
    return 0;
}