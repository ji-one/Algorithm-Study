// 3184 양

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int r,c;
char map[251][251];
int visit[251][251];

int live[251*251][2];   // [a][b] a 영역에 b = 0 : 양 / b =1 : 늑대 

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool isInside(int x, int y) {
    return x>=0 && x<r && y>=0 && y<c;
}

void bfs(int x, int y, int idx) {
    queue<pair<int, int> > q;
    q.push({x,y});
    visit[x][y] = idx;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if(map[cx][cy] == 'v') {
            live[idx][1]++;
        } else if(map[cx][cy] == 'o') {
            live[idx][0]++;
        }
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx,ny) && !visit[nx][ny] && map[nx][ny] != '#') {
                visit[nx][ny] = idx;
                q.push({nx,ny});
            }
        }
    }
}
int main() {
    cin >> r >>c ;
    for(int i=0; i<r; i++) {
        string s;
        cin>>s;
        for(int j=0; j<c; j++) {
            map[i][j] = s[j];
        }
    }

    int idx = 1;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(!visit[i][j] && map[i][j] != '#') {
                bfs(i,j,idx);
                idx++;
            }
        }
    }

    int s=0, w=0; // 양 늑대
    for(int i=1; i<=idx; i++) {

        if(live[i][0] > live[i][1]) {
            s += live[i][0];
        } else {
            w += live[i][1];
        }
    }

    cout << s << ' ' << w;
    return 0;
}