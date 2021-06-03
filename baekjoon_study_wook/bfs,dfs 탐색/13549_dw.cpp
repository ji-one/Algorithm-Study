// 13549 숨바꼭질 3

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
    priority_queue<pair<int, int> > pq;
    
    pq.push({0,n});
    visit[n] = 1;

    while(!pq.empty()) {
        int ct = -pq.top().first;
        int cx = pq.top().second;
        pq.pop();
        
        if(cx == k) {
            return ct;
        }
        if(isInside(cx-1) && visit[cx-1] == 0) {
            pq.push({-(ct+1), cx-1});
            visit[cx-1] = ct+1;
        }

        if(isInside(cx+1) && visit[cx+1] == 0) {
            pq.push({-(ct+1), cx+1});
            visit[cx+1] = ct+1;
        }

        if(cx != 0 && isInside(cx*2) && (visit[cx*2] == 0 || visit[cx*2] > ct)) {
            pq.push({-ct, cx*2});
            visit[cx*2] = ct;
        }
    }
}
int main(){
    cin >> n >> k;
    
    cout << bfs();

    return 0;
}