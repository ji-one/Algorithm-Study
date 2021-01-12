#include <iostream>
#include <vector>
using namespace std;
int k;
int lotto[13];
int comb[6];
void dfs(int idx, int depth)
{
    if (depth == 6)
    {
        for (int i = 0; i < 6; i++)
		{
			cout << comb[i] << ' ';
		}
		cout << '\n';
		return;
    }

    for (int i = idx; i < k; i++)
    {
        comb[depth] = lotto[i];
        dfs(i + 1, depth + 1);
    }
}

int main()
{
    while (1)
    {
        cin >> k;
        if (k == 0)
            break;
        for (int i = 0; i < k; i++)
        {
            cin >> lotto[i];
        }
        dfs(0, 0);
        cout << '\n';
    }

    return 0;
}