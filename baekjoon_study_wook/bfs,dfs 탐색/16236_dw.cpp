// 16236 아기 상어
#include <iostream>
#include <queue>

using namespace std;

int n;
int space[21][21];
int visit[21][21];
int sharkX, sharkY, sharkLevel, cnt;

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

bool isInside(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

int bfs(int x, int y) {
    space[x][y] = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{x,y}, 0});
    visit[x][y] = 1;
    int minDist = 10000;

    while(!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int ct = q.front().second;
        q.pop();

        if(sharkLevel < space[cx][cy]) continue;

        if(space[cx][cy] > 0 && sharkLevel > space[cx][cy]) {
            if(minDist >= ct) {
                if(minDist == ct) {
                    if(x > cx) {
                        x = cx;
                        y = cy;
                    }
                    if(x == cx) {
                        if(y > cy) {
                            y = cy;
                        }
                    }
                } else {
                    x = cx;
                    y = cy;
                    minDist = ct;
                }
            }
            continue;
        } 
        for(int i =0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx, ny) && !visit[nx][ny]) {
                q.push({{nx,ny}, ct+1});
                visit[nx][ny] = 1;
            }
        }
    }

    if(minDist != 10000) {
        sharkX = x;
        sharkY = y;
        space[sharkX][sharkY] = 9;
        cnt++;
        if(cnt == sharkLevel) {
            sharkLevel++;
            cnt = 0;
        }
        return minDist;
    }
    
    return 0;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> space[i][j];
            if(space[i][j] == 9) {
                sharkX = i;
                sharkY = j;
            }
        }
    }
    sharkLevel = 2;

    int t = 0;
    while(1) {
        bool exit = false;
        
        int tmp = bfs(sharkX, sharkY);
        if(tmp > 0) {
            t += tmp;
        } else {
            exit = true;
        }
        fill(&visit[0][0], &visit[n-1][n], 0);
        if(exit) break;
    }

    cout << t;
    return 0;
}