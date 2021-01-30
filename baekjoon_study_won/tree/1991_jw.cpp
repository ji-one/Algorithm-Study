#include <iostream>
using namespace std;
class
{
public:
    char left;
    char right;
} node[100];
void preorder(char root) // 전위
{
    cout << root;
    if (node[root].left != '.')
        preorder(node[root].left);
    if (node[root].right != '.')
        preorder(node[root].right);
}
void inorder(char root) // 중위
{
    if (node[root].left != '.')
        inorder(node[root].left);
    cout << root;
    if (node[root].right != '.')
        inorder(node[root].right);
}
void postorder(char root) // 후위
{
    if (node[root].left != '.')
        postorder(node[root].left);
    if (node[root].right != '.')
        postorder(node[root].right);
    cout << root;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        node[t1].left = t2;
        node[t1].right = t3;
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout<<'\n';
    postorder('A');
    return 0;
}
