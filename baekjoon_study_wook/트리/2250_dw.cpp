// 2250 트리의 높이와 너비  솔루션 봄
#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[10001];
int node[10001];        // 0이면 부모노드
int minColumn[10001];    // x레벨의 최소 열
int maxColumn[10001];    // x레벨의 최대 열

int column;
int height;

void inOrder(int x, int level) {

    if(tree[x][0] != -1) {
        inOrder(tree[x][0], level+1);
    }

    column++;
    // 최소 열 구하기
    if(minColumn[level] > column) {
        minColumn[level] = column;
    }
    // 최대 열 구하기
    if(maxColumn[level] < column) {
        maxColumn[level] = column;
    }
    // 높이 구하기
    if(height < level) {
        height = level;
    }

    if(tree[x][1] != -1) {
        inOrder(tree[x][1], level+1);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int parent, left, right;
        cin >> parent >> left >> right;
        tree[parent].push_back(left);
        tree[parent].push_back(right);
        node[left]++;
        node[right]++;
    }
    fill(minColumn, minColumn+n+1, 111111);
    // 루트 노드 찾기
    int root = 0;
    for(int i=1; i<=n; i++) {
        if(node[i] == 0) {
            root = i;
        }
    }

    inOrder(root, 1);

    int level = 0;
    int width = 0;
    for(int i=1; i<=height; i++) {
        if(maxColumn[i] - minColumn[i] + 1 > width) {
            level = i;
            width = maxColumn[i] - minColumn[i] + 1;
        }
    }

    cout << level << ' ' << width;
    return 0;
}