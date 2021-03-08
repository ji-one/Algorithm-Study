#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int inorder[1024];
int preorder[1024];
int n = 1;
vector<int> res[11];
void Preorder(int s, int e)
{
    if (s > e)
        return;
    int m = (e + s) / 2;
    preorder[n++] = inorder[m];
    Preorder(s, m - 1);
    Preorder(m + 1, e);
}
void order(int s, int e, int k)
{
    if (s > e)
        return;
    res[k].push_back(preorder[s]);
    int size = (e - s) / 2;
    order(s + 1, s + size, k + 1);
    order(s + size + 1, e, k + 1);
}
int main()
{
    int k;
    cin >> k;
    for (int i = 1; i <= pow(2, k) - 1; i++)
        cin >> inorder[i];

    Preorder(1, pow(2, k) - 1);
    order(1, pow(2, k) - 1, 0);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}