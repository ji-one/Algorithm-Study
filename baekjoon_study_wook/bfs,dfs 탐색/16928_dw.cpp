// 16928 뱀과 사다리 게임

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int game[101];
int visit[101];
int moved[101];

int bfs(int start) {
    queue<pair<int,int>> q;
    q.push({start, 0});
    visit[start] = 1;
    while(!q.empty()) {
        int cx = q.front().first;
        int ct = q.front().second;
        q.pop();

        if(cx == 100) {
            return ct;
        }

        for(int i=1; i<=6; i++) {
            int nx = cx+i;
            if(moved[nx] != 0) nx = moved[nx];
            if(!visit[nx] && nx<=100) {
                visit[nx] = 1;
                q.push({nx, ct+1});

            }
        }
    }
}
int main() {

    cin >> n >> m;

    for(int i=0; i<n+m; i++) {
        int x, y;
        cin >> x >>y;
        moved[x] = y;
    }

    cout << bfs(1);
    return 0;
}