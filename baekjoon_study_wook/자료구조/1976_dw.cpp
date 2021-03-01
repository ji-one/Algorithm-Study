// 1976 여행 가자
// union_find
#include<iostream>

using namespace std;

int n,m;
int con[201][201];
int plan[1001];
int parent[201];

int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}
void _union(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a<b) parent[b] = a;
    else    parent[a] = b;
}
bool _find(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) return true;
    else        return false;
}
int main(){
    cin >> n >>m;

    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> con[i][j];
            if(con[i][j] == 1){ 
                _union(i,j);
            }
        }
    }

    for(int i=0; i<m; i++){
        cin >> plan[i];
    }

    int tmp = parent[plan[0]];
    bool f = true;
    for(int i=1; i<m; i++){
        if(_find(tmp, parent[plan[i]])) continue;
        f = false;
        break;
    }
    if(f) cout << "YES";
    else  cout << "NO";
    return 0;
}