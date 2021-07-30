// 16946 벽 부수고 이동하기 4

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n,m;
int map[1001][1001];

int map2[1001][1001];   // [x][y] 에 이어지는 땅의 인덱스 저장
int moved[1000001]; // move[x] : x 번에 이동 횟수 저장
bool check[1000001];

bool visit[1001][1001];

string ans[1001];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool isInside(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

int bfs(int x, int y, int index) {
    queue<pair<int, int> > q;
    q.push({x,y});
    map2[x][y] = index;
    visit[x][y] = true;
    int rst = 0;
    
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        rst++;

        q.pop();
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(isInside(nx,ny) && !visit[nx][ny] && map[nx][ny] == 0) {
                map2[nx][ny] = index;
                visit[nx][ny] = true;
                q.push({nx, ny});

            }
        }
    }

    return rst;
}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<m; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    int idx= 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 0 && !map2[i][j]) {
                moved[idx] = bfs(i, j, idx);
                idx++;
            }
        }
    }

    /*
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << map2[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i=1; i<idx; i++) {
        cout << moved[i] << ' ';
    }
    */

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int temp = 0;
            if(map2[i][j] == 0) {
                temp++;
                for(int k=0; k<4; k++) {
                    int nextIndexX = i+ dx[k];
                    int nextIndexY = j+ dy[k];
                    int movedIndex = map2[nextIndexX][nextIndexY];
                    if(isInside(nextIndexX, nextIndexY) && !check[movedIndex]) {
                        temp += moved[movedIndex]; 
                        check[movedIndex] = true;                       
                    }    
                }
            }
            fill(check, check + idx, false);
            temp %= 10;
            ans[i] += (temp + '0');
        }
    }
    for(int i=0; i<n; i++) {
        cout << ans[i] << '\n';

    }
    return 0;
}