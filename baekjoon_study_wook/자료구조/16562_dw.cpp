// 16562 친구비

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k;
vector<pair<int, int> > students;
int parent[10001];
bool friends[10001];

int getParent(int node) {
    if(parent[node] == node) return node;
    return parent[node] = getParent(parent[node]); 
}

void _union(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a<b) parent[b] = a;
    else    parent[a] = b;
}

int main() {
    cin >>n >> m >> k;
    for(int i=1; i<=n; i++) {
        int cost;
        cin >>cost;
        students.push_back({cost, i});
        parent[i] = i;
    }

    for(int i=0; i<m; i++) {
        int v, w;
        cin >> v >> w;
        _union(v,w);
    }

    sort(students.begin(), students.end());
    
    int sum =0;
    bool all = false;
    for(int i=0; i<n; i++) {
        
        all = false;
        if(friends[getParent(students[i].second)]) {
            continue;
        }
        if(k>=students[i].first) {
            k-=students[i].first;
            sum += students[i].first;
            friends[getParent(students[i].second)] = true;
        } else {
            break;
        }
        
        all = true;
        for(int j=1; j<=n; j++) {
            if(friends[getParent(j)] == false) {
                all = false;
                break;
            }
        }
        if(all) {
            break;
        }
        
    }
    
    if(all) {
        cout << sum <<'\n';
    } else {
        cout << "Oh no" << '\n';
    }

    // for(int i=1; i<=n ;i++) {
    //     cout << getParent(i) << ' ';
    // }
    return 0;
}