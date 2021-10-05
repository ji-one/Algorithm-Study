// 1325 효율적인 해킹

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<int> com[10001];
int visit[10001];

int bfs(int start) {
    queue<int> q;
    q.push(start);
    visit[start] = 1;
    int hacking = 1;

    while(!q.empty()) {
        int cx = q.front();
        q.pop();
        for(int i=0; i<com[cx].size(); i++) {
            if(visit[com[cx][i]]) continue;
            q.push(com[cx][i]);
            visit[com[cx][i]] = 1;
            hacking++;
        }
    }

    return hacking;
}
int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        com[b].push_back(a);
    }

    
    int maxCnt = 0;
    vector<int> num;
    for(int i=1; i<=n; i++) {
        fill(visit, visit+n+1, 0);
        int cnt = bfs(i);
        if(maxCnt <= cnt) {
            if(maxCnt < cnt) {
                num.clear();
                maxCnt = cnt;
            }
            num.push_back(i);
        }
    }

    sort(num.begin(), num.end());
    for(int number : num) {
        cout << number << ' ';
    }
    return 0;
}