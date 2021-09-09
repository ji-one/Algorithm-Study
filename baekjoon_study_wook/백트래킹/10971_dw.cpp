// 10971 외판원 순회 2

#include <iostream>

using namespace std;


int wp[11][11];
int n, answer = 987654321;
bool visit[11];

void dfs(int start, int cnt, int cost, int end) {
    // cout << start << ' ';
    if(cnt == n) {
        // cout << '\n';
        if(wp[start][end] > 0) {
            cost += wp[start][end];
            if(cost < answer) {
                answer = cost;
            }
        } 
        
        return ;
    }

    for(int i=0; i<n; i++) {
        if(visit[i]) continue;
        if(wp[start][i] == 0) continue;
        visit[i] = true;
        dfs(i, cnt+1, cost + wp[start][i], end);
        visit[i] = false;
    }
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0 ;j<n ;j++) {
            cin >> wp[i][j] ;
        }
    }
    for(int i=0; i<n; i++) {
        visit[i] = true;
        dfs(i, 1, 0, i);
        
        visit[i] = false;
    }
    cout << answer;
    return 0;
}