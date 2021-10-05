// 1197 최소 스패닝 트리

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct COST {
    int cost;
    int a;
    int b;
};

int v, e;
vector<COST> cost;

int parent[10001];
bool cmp(COST c1, COST c2) {
    return c1.cost < c2.cost;
}

int getParent(int n) {
    if(parent[n] == n) return n;
    return parent[n] = getParent(parent[n]);
}

void _union(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a>b) parent[b] = a;
    else parent[a] = b;

    return ;
}
bool find(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a == b) return true;
    return false;
}
int main() {
    cin >> v >> e;
    for(int i=0; i<=v; i++) {
        parent[i] = i;
    }
    
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a>> b>> c; 
        cost.push_back({c, a, b});        
    }
    sort(cost.begin(), cost.end(), cmp);

    int rst =0;
    for(int i=0; i<e; i++) {
        
        // 사이클 확인
        if(find(cost[i].a, cost[i].b)) continue;
        _union(cost[i].a, cost[i].b);
        
        rst += cost[i].cost;
    }

    cout << rst;
    return 0;
}