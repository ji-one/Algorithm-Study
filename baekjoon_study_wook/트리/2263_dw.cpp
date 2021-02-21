// 2263 트리의 순회
/*
    솔루션 봄
    전위 순회 : 부모 -> 왼쪽 -> 오른쪽
    중위      : 왼쪽 -> 부모 -> 오른쪽
    후위      : 왼쪽 -> 오른쪽 -> 부모
    후위 순회의 마지막 노드는 루트이다.
    루트를 기준으로 중위 순회의 좌 우는 왼쪽서브트리와 오른쪽 서브트리로 나뉜다.
    후위 순회에서는 중위 순회에서 루트를 기준으로 나눠진 수만큼 왼쪽 오른쪽으로 나뉜다.
    이를 통해 다시 서브트리의 루트를 찾는 방식을 반복한다.
*/
#include <iostream>

using namespace std;

int n;
int in[100001];
int post[100001];
int pos[100001];

void solve(int in_start, int in_end, int post_start, int post_end){
    if(in_start>in_end || post_start>post_end) return ;
    int root = post[post_end];
    cout << root << ' ';
    int p = pos[root]; // inorder에서 루트의 위치
    int left = p - in_start;    // 나눠지는 개수 확인
    solve(in_start, p-1, post_start, post_start + left - 1); // 왼쪽
    solve(p+1, in_end, post_start + left, post_end -1); // 오른쪽
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> in[i];
    }
    for(int i=0; i<n; i++){
        cin >> post[i];
    }
    for(int i=0; i<n; i++){
        pos[in[i]] = i; // 인오더 노드의 위치
    }
    solve(0,n-1,0,n-1);

    return 0;
}