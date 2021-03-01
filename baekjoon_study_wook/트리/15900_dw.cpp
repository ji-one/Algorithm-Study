// 15900 나무 탈출 솔루션 봄

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> edge[500001];
int visit[500001];
int rst;
void dfs(int level, int root){
    visit[root] = 1;
    
    bool leaf = true;
    for(int i=0; i<edge[root].size(); i++){
        if(!visit[edge[root][i]]){
            dfs(level + 1, edge[root][i]);
            leaf = false;
        }
    }

    if(leaf){
        rst+= level;
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(0, 1);

    // 리프 노드의 높이가 홀수면 이기고 짝수면 진다.
    if(rst%2){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}
