#include <iostream>
#include <algorithm>
using namespace std;
struct
{
    int left, right;
} node[1000002];

void postOrder(int root)
{
    if (root == 0)
        return;
    postOrder(node[root].left);
    postOrder(node[root].right);
    cout << root << '\n';
}
int main()
{
    int root;
    cin >> root;
    int num;
    while (cin >> num)
    {
        int cur = root;
        while (1)
        {
            if (num < cur)
            {
                if (node[cur].left != 0)
                    cur = node[cur].left;
                else
                {
                    node[cur].left = num;
                    break;
                }
            }
            else
            {
                if (node[cur].right != 0)
                    cur = node[cur].right;
                else
                {
                    node[cur].right = num;
                    break;
                }
            }
        }
    }
    postOrder(root);
    return 0;
}