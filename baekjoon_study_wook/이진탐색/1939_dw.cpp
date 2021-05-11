// 1939 중량제한
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,m, s,e, rst;
vector<pair<int, int>> v[10001];
int visit[10001];

bool bfs(int w){
    queue<int> q;
    q.push(s);
    visit[s] = 1;

    while(!q.empty()){
        int cx = q.front();
        q.pop();

        if(cx == e){
            return true;
        }
        
        for(int i=0; i<v[cx].size(); i++){
            int nx = v[cx][i].first;
            int ncost = v[cx][i].second;
            // 지나갈 수 있으면
            if(!visit[nx] && ncost >= w){
                q.push(nx);
                visit[nx] = 1;
            }
        }

    }
    return false;
}
void binarySearch(int start, int end){
    int left = start;
    int right = end;
    while(left<=right){
        memset(visit, 0, sizeof(visit));
        int mid = (left+right)/2;
        if(bfs(mid)){
            rst = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ;
}
int main(){
    cin >> n >> m;
    int max_value= 0;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        max_value = max(max_value, c);
    }
    cin >> s >> e;
    binarySearch(1,max_value);
    cout << rst;
    return 0;
}