// 1068 트리

#include <iostream>
#include <vector>

using namespace std;

struct TREE {
    int node;
    int parent;
    vector<int> child;    

};

int n;
TREE tree[52];

int answer;

void dfs(int node) {
    if(tree[node].child.size() == 0) {
        answer++;
        return ;
    }
    for(int i=0; i<tree[node].child.size(); i++) {
        int children = tree[node].child[i];
        dfs(children);
    }
}
int main() {
    cin >> n;
    int root = 0;
    for(int i=0; i<n; i++) {
        int p;
        cin >> p;
        if(p == -1) {
            root = i;
        } else {
            tree[i].parent = p;
            tree[p].child.push_back(i);
        }
    }

    int delNode;
    cin >> delNode;

    if(delNode == root) {
        cout << 0;
        return 0;
    }
    int delNodeParent;
    delNodeParent = tree[delNode].parent;
    
    for(int i=0; i<tree[delNodeParent].child.size(); i++) {
        if(tree[delNodeParent].child[i] == delNode) {
            tree[delNodeParent].child.erase(i+tree[delNodeParent].child.begin());
        }
    }

    dfs(root);
    cout << answer;
    return 0;
}