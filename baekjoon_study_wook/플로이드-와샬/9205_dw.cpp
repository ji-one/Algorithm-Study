// 9205 맥주 마시면서 걸어가기
// 솔루션 봄
#include <iostream>
#include <vector>
using namespace std;

int t, n;
vector<pair<int, int>> v;
int dist[111][111];
int INF = 987654321;

void floyd(){
    
    for(int k=0; k<n+2; k++){
        for(int i=0; i<n+2; i++){
            for(int j=0; j<n+2; j++){
                if(i==j) continue;
                
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
int main(){
    cin >>t;
    while(t--){
        cin >> n;
        for(int i=0; i<n+2; i++){
            for(int j=0; j<n+2; j++){
                if(i == j) dist[i][j] = 0;  
                else    dist[i][j] = INF;
            }
        }
        int x, y;
        cin >> x >> y;  // 집
        v.push_back({x,y});
        for(int i=0; i<n; i++){ // 편의점
            cin >> x >> y;
            v.push_back({x,y});
        }
        cin >> x >> y;  // 목적지
        v.push_back({x,y});

        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
                if(i == j) continue;
                int tmp = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
                if(tmp <= 1000){
                    dist[i][j] = 1; // i번에서 j번으로 갈 수 있음
                }
            }
        }
        floyd();
        
        if(dist[0][n+1] == INF) cout << "sad\n";
        else    cout << "happy\n";

        v.clear();
    }
    return 0;
}