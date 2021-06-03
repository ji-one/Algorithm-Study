// 13913 숨바꼭질 4
#include <iostream>

#include <iostream>
#include <queue>
#include <vector>

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
    
    cout << bfs() << '\n';
    
    vector<int> v;
    int x = k;
    if(k == n) {
        cout << k;
    } else {
        while(visit[x] != 1) {
            v.push_back(x);
            
            if((x/2) * 2 == x) {
                if(isInside(x/2) && visit[x/2] == visit[x]-1) {
                    x/=2;
                } else if(isInside(x+1) && visit[x+1] == visit[x]-1) {
                    x+=1;
                } else if(isInside(x-1) && visit[x-1] == visit[x]-1) {
                    x-=1;
                }
            } else if(isInside(x+1) && visit[x+1] == visit[x]-1) {
                x+=1;
            } else if(isInside(x-1) && visit[x-1] == visit[x]-1) {
                x-=1;
            }
        }
        v.push_back(x);
        for(int i=v.size()-1; i>=0; i--) {
            cout << v[i] << ' ';
        }
    }
    
    return 0;
}