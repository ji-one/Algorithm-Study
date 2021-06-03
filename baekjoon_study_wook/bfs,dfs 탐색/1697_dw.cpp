// 1697 숨바꼭질

#include <iostream>
#include <queue>

using namespace std;

int n,k;
int visit[100001];
int pos[100001];

bool isInside(int x) {
    return x>=0 && x<=100000;
}

int bfs() {
    queue<int> q;
    q.push(n);
    visit[n] = 1;

    while(!q.empty()) {
        int cx = q.front();
        q.pop();
        
        if(cx == k) {
            return visit[cx] - 1;
        }
        if(isInside(cx-1) && visit[cx-1] == 0) {
            q.push(cx-1);
            visit[cx-1] = visit[cx] + 1;
        }

        if(isInside(cx+1) && visit[cx+1] == 0) {
            q.push(cx+1);
            visit[cx+1] = visit[cx] + 1;
        }

        if(isInside(cx*2) && visit[cx*2] == 0) {
            q.push(cx*2);
            visit[cx*2] = visit[cx] + 1;
        }
    }
}
int main(){
    cin >> n >> k;
    
    cout << bfs();

    return 0;
}