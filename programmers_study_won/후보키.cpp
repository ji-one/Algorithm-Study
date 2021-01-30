#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int col, row;
bool check[10];
int answer;
int tmp[10];
vector<vector<string>> r;
vector<string> can;
void comb(int idx, int cnt, int n)
{
    if (cnt == n)
    {
        unordered_map<string, int> m;
        for (int i = 0; i < row; i++)
        {
            string s = "";
            for (int j = 0; j < n; j++)
            {
                s += r[i][tmp[j]];
            }
            m[s]++;
        }
        bool flag = true;

        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second > 1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            string candi = "";
            for (int i = 0; i < n; i++)
                candi += to_string(tmp[i]);

            for (int i = 0; i < can.size(); i++)
            {
                int count = 0;
                for (int j = 0; j < can[i].length(); j++)
                {
                    for (int k = 0; k < candi.length(); k++)
                    {
                        if (candi[k] == can[i][j])
                            ++count;
                    }
                }
                if (count == can[i].length())
                    return;
            }
            cout << candi << '\n';
            can.push_back(candi);
        }
        return;
    }

    for (int i = idx; i < col; i++)
    {
        tmp[cnt] = i;
        comb(i + 1, cnt + 1, n);
    }
}
int solution(vector<vector<string>> relation)
{
    r = relation;
    col = relation[0].size();
    row = relation.size();

    for (int i = 1; i <= col; i++)
        comb(0, 0, i);
    answer = can.size();
    return answer;
}