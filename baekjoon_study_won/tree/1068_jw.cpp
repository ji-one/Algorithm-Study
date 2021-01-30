#include <iostream>
#include <vector>
using namespace std;
vector<int> v[51];
int cnt = 0;
int del; // delete
void search(int root)
{
    if (root == del)
        return;
    if (v[root].size() == 0)
    {
        ++cnt;
        return;
    }
    for (int i = 0; i < v[root].size(); i++)
    {
        int child = v[root][i];
        if(child == del && v[root].size() == 1)
        {
            ++cnt;
        }
        else search(child);
    }
}
int main()
{
    int n, root, p;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        if (p == -1)
            root = i;
        else
            v[p].push_back(i);
    }
    cin >> del;
    search(root);
    cout << cnt;
}