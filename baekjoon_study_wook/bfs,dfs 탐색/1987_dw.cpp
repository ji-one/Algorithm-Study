// 1987 알파벳
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int R, C;
string s[21];
int alpa[26];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int ans;

void dfs(int x, int y, int cnt){
    
    int c = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>=0 && nx<R && ny >=0 && ny<C){
            // cout << x << ", " << y << '\n';

            if(alpa[s[nx][ny]-'A'] == 0){
                alpa[s[nx][ny]-'A'] = 1;
                dfs(nx,ny,cnt+1);
                alpa[s[nx][ny]-'A'] = 0;
            }
        
        }
    }
    ans = max(ans, cnt);
    return ;
}
int main(){
    cin >> R >> C;
    for(int i=0; i<R; i++){
        cin >> s[i];
    }
    alpa[s[0][0] - 'A'] = 1;
    dfs(0,0,1);
    cout << ans;
    return 0;
}