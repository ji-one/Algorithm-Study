// 15654  N과 M(5)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> num;
int visit[10];

void dfs(int cnt){
    if(cnt == m){
        for(int i=0 ; i<m; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return ;
    }
    for(int i=0; i<v.size(); i++){
        if(visit[i]) continue;
        visit[i] = 1;
        num.push_back(v[i]);
        dfs(cnt+1);
        num.pop_back();
        visit[i] = 0;
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    dfs(0);
    return 0;
}