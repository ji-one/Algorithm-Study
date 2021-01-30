#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool checked[3];
char oper[3] = {'+', '-', '*'}; // + - * 순열
int comb[3];
vector<long long> n;
vector<char> op;
long long answer;
long long rst;
void Calc()
{
    vector<long long> tmp1 = n;
    vector<char> tmp2 = op;
    for (int k = 0; k < 3; k++)
    {
        for (int i = 0; i < op.size(); i++)
        {
            if (oper[comb[k]] == op[i])
            {
                if (op[i] == '+')
                {
                    rst = n[i] + n[i + 1];
                }
                if (op[i] == '-')
                {
                    rst = n[i] - n[i + 1];
                }
                if (op[i] == '*')
                {
                    rst = n[i] * n[i + 1];
                }
                n[i] = rst;
                n.erase(n.begin() + i + 1);
                op.erase(op.begin() + i);
                --i;
            }
        }
    }
    rst = abs(n[0]);
    n = tmp1;
    op = tmp2;
    return;
}
void search(int idx)
{ // 0 1 2 ..
    if (idx == 3)
    {
        Calc();
        answer = max(rst, answer);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (!checked[i])
        {
            checked[i] = true;
            comb[idx] = i;
            search(idx + 1);
            checked[i] = false;
        }
    }
}

long long solution(string expression)
{

    string num = "";

    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            num += expression[i];
        }
        else
        {
            n.push_back(stoi(num));
            num = "";
            op.push_back(expression[i]);
        }
        if (i == expression.length() - 1)
        {
            n.push_back(stoi(num));
        }
    }
    search(0);
    return answer;
}