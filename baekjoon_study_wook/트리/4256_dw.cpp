// 4256 트리

#include <iostream>

using namespace std;

int pre[1001];
int in[1001];

void divide(int preStart, int preEnd, int inStart, int inEnd) {
    if(preStart>preEnd || inStart>inEnd) return ;

    int root = pre[preStart];
    int pos;
    for(int i=inStart; i<=inEnd; i++) {
        if(in[i] == root) {
            pos = i;
        }
    }
    int left = pos - inStart;
    divide(preStart+1, preStart + left , inStart,  pos-1);
    divide(preStart+left+1 , preEnd, pos+1, inEnd);
    cout << root << ' ';
}
int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> pre[i];
        }
        for(int i=0; i<n; i++) {
            cin >> in[i];
        }
        divide(0, n-1, 0, n-1);
        cout << '\n';
    }
    return 0;
}