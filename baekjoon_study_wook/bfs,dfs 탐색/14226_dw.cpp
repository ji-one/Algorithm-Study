// 14226 이모티콘
#include <iostream>
#include <queue>

using namespace std;

int s;
int dp[2000][2000]; // dp[a][b] = c  클립보드에 a 개 있고
                    //              화면에 b 개 있을 때 시간 c

bool isInside(int x, int y) {
    return x>=0 && x<=2000 && y>=0 && y<=2000;
}

int bfs() {
    queue<pair<int,int>> q;
    q.push({0,1}); // 클립보드, 화면
    dp[0][1] = 1;

    while(!q.empty()) {
        int clip = q.front().first;
        int screen = q.front().second;
        q.pop();

        if(screen == s) {
            return dp[clip][screen] - 1;
        }
        // 1.
        if(isInside(clip, screen) && dp[screen][screen] == 0) {
            q.push({screen, screen});
            dp[screen][screen] =  dp[clip][screen] + 1;
        }

        // 2.
        if(isInside(clip, screen) && dp[clip][clip + screen] == 0) {
            q.push({clip, clip + screen});
            dp[clip][clip + screen] = dp[clip][screen] + 1;
        }

        // 3.
        if(isInside(clip, screen) &&  dp[clip][screen - 1] == 0) {
            q.push({clip, screen - 1});
            dp[clip][screen - 1] = dp[clip][screen] + 1;
        }

    }
}
int main() {
    cin >> s;
    cout << bfs();
    
    return 0;
}