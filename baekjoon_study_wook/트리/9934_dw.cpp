// 9934 완전 이진 트리

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int k,n;
int tree[1030];
vector<int> node[11];

// 완전 이진 트리이므로 노드 수는 항상 홀수이고,
// 중간 노드가 트리의 루트
void solve(int cnt, int start, int end){
    if(cnt == k) return ;
    int mid = (start+end)/2;

    node[cnt].push_back(tree[mid]);

    solve(cnt+1, start, mid-1);
    solve(cnt+1, mid+1, end);
}


int main(){
    cin >> k;
    n = pow(2,k) - 1;
    for(int i=0; i<n; i++){
        cin >> tree[i];
    }
    solve(0,0,n);
    for(int i=0 ;i<k; i++){
        for(int j=0; j<node[i].size(); j++){
            cout << node[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}