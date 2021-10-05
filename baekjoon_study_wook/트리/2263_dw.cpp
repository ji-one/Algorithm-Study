// 2263 트리의 순회

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int inorder[100001];
int postorder[100001];

void divide(int inStart, int inEnd, int postStart, int postEnd) {
    if(inStart>inEnd || postStart>postEnd) return ;
    
    int root = postorder[postEnd];
    cout << root << ' ';
    
    int pos;
    
    for(int i=inStart; i<=inEnd; i++) {
        if(root == inorder[i]) {
            pos = i;
        }
    }
    int left = pos - inStart;
    divide(inStart, pos-1, postStart, postStart + left -1);
    divide(pos+1, inEnd, postStart+left, postEnd-1);
} 

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> inorder[i];
    }
    for(int i=0; i<n; i++) {
        cin >> postorder[i];
    }

    divide(0, n-1, 0, n-1);

    return 0;
}