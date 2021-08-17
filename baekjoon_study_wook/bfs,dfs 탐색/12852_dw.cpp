// 1로 만들기 2

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int visit[1000001];
int answer;

int bfs(int x) {
    queue<pair<int, int>> q;
    q.push({x, 0});
    visit[x] = x;
    while(!q.empty()) {
        int cx = q.front().first;
        int ct = q.front().second;
        q.pop();

        if(cx == 1) {
            return ct;
        }

        if(cx%3 == 0 && !visit[cx/3]) {
            q.push({cx/3, ct+1});
            visit[cx/3] = cx;
        }

        if(cx%2 == 0 && !visit[cx/2]) {
            q.push({cx/2, ct+1});
            visit[cx/2] = cx;
        }

        if(!visit[cx-1]) {
            q.push({cx-1, ct+1});
            visit[cx-1] = cx;
        }
    }
}

int main() {
    cin >> n;
    cout << bfs(n) << '\n';

    vector<int> v;
    int x = 1;
    while(x!=n) {
        v.push_back(x);
        x = visit[x];
    }
    v.push_back(n);
    for(int i=v.size()- 1;i>=0; i--) {
        cout << v[i] << ' ';
    }
    return 0;
}