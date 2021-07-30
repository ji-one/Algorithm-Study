// 1103 게임

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n,m, ans;
int board[51][51];
int visit[51][51];
int dp[51][51];

bool pass = false;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

bool isInside(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

int dfs(int cx, int cy) {
    
    if(!isInside(cx, cy) || board[cx][cy] == 'H' - '0') {
        return 0;
    }

    if(visit[cx][cy]) {
        pass = true;
    }
    if(dp[cx][cy] != -1) return dp[cx][cy];

    visit[cx][cy] = 1;
    dp[cx][cy] = 0;

    int x = board[cx][cy];
    for(int i=0; i<4; i++) {
        int nx = cx + dx[i]*x;
        int ny = cy + dy[i]*x;
        dp[cx][cy] = max(dp[cx][cy], dfs(nx, ny) + 1);
    }
    visit[cx][cy] = 0;

    return dp[cx][cy];
}

/*
int bfs() {
    queue<pair<int, pair<int, int> >> q;
    q.push({1, {0,0}});
    visit[0][0] = 1;

    while(!q.empty()) {
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        int x = board[cx][cy];

        int cnt = q.front().first;
        q.pop();

        if(cnt > ans) {
            ans = cnt;
        }

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i]*x;
            int ny = cy + dy[i]*x;
            
            if(!isInside(nx, ny)) continue;
            if(visit[nx][ny]) return -1;
            if(board[nx][ny] == 'H' - '0') continue;
            visit[nx][ny] = 1;
            q.push({cnt+1, {nx,ny}});
        }
        
    }
    return ans;
}
*/

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<m; j++) {
            board[i][j] = s[j] - '0';
        }

    }
    fill(&dp[0][0], &dp[n-1][m], -1);
    // cout << bfs();
    dfs(0,0);

    if(pass) {
        cout << -1;
    } else {
        cout << dp[0][0];
    }

    return 0;
}