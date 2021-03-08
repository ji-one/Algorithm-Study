#include <iostream>
using namespace std;
int inorder[100000];
int postorder[100000];
int idx[100001];
// solution
void getPreorder(int is, int ie, int ps, int pe)
{
    if (is > ie || ps > pe)
        return;

    cout << postorder[pe] << ' ';

    int root_idx = idx[postorder[pe]];
    int leftSize = root_idx - is;
    int rightSize = ie - root_idx;

    getPreorder(is, root_idx - 1, ps, ps + leftSize - 1);
    getPreorder(root_idx + 1, ie, ps + leftSize, pe - 1);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    for (int i = 0; i < n; i++)
        cin >> postorder[i];
    for (int i = 0; i < n; i++)
        idx[inorder[i]] = i; // inorder 숫자 위치. root를 inorder에서 찾기 위해
    getPreorder(0, n - 1, 0, n - 1);
}