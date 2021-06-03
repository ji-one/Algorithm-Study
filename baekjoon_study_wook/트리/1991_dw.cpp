// 1991 트리 순회
#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[30];

void preOrder(int parent) {
    char node = parent + 'A';
    cout << node;

    for(int i=0; i<tree[parent].size(); i++) {
        if(tree[parent][i] != '.') {
            preOrder(tree[parent][i] - 'A');
        }
    }
}

void inOrder(int parent) {
    char node = parent + 'A';
    
    if(tree[parent][0] != '.') {
        inOrder(tree[parent][0] - 'A');
    }

    cout << node;

    if(tree[parent][1] != '.') {
        inOrder(tree[parent][1] - 'A');
    }
}

void postOrder(int parent) {
    char node = parent + 'A';

    for(int i=0; i<tree[parent].size(); i++) {
        if(tree[parent][i] != '.') {
            postOrder(tree[parent][i] - 'A');
        }
    }
    cout << node;

}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        char node, left, right;
        cin >> node >> left >> right;
        tree[node - 'A'].push_back(left);
        tree[node - 'A'].push_back(right);
    }
    preOrder(0);
    cout << '\n';
    inOrder(0);
    cout << '\n';
    postOrder(0);
    
}