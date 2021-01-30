#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
vector<char> v[30];
set<int> e[30];
bool check(int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        e[i].clear();
    }

    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            char tmp = v[i][j];
            if (tmp != '0' && tmp == v[i + 1][j] && tmp == v[i][j + 1] && tmp == v[i + 1][j + 1])
            {
                flag = true;
                e[i].insert(j);
                e[i].insert(j + 1);
                e[i + 1].insert(j);
                e[i + 1].insert(j + 1);
            }
        }
    }
    return flag;
}
int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            v[i].push_back(board[j][i]);
        }
    }

    while (check(m, n))
    {
        for (int i = 0; i < n; i++)
        {
            int num = 0;
            for (auto it = e[i].begin(); it != e[i].end(); it++)
            {
                int x = *it;
                x -= num;
                ++num;
                v[i].erase(v[i].begin() + x);
                v[i].push_back('0');
                ++answer;
            }
        }
    }

    return answer;
}