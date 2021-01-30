#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void makeElement(string str, vector<string> &v)
{
    for (int i = 0; i < str.length() - 1; i++)
    {
        string s = "";
        int j;
        for (j = i; j < i + 2; j++)
        {
            if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z'))
            {
                s += tolower(str[j]);
            }
            else
                break;
        }
        if (j == i + 2)
        {
            v.push_back(s);
        }
    }
}
void insertMap(vector<string> v, unordered_map<string, int> &m)
{
    for (int i = 0; i < v.size(); i++)
    {
        m[v[i]]++;
    }
}
int solution(string str1, string str2)
{
    int answer = 0;
    double uni = 0.0;
    double inter = 0.0;
    vector<string> v1;
    vector<string> v2;
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;

    makeElement(str1, v1);
    makeElement(str2, v2);

    insertMap(v1, m1);
    insertMap(v2, m2);

    for (auto it = m1.begin(); it != m1.end(); it++)
    {
        inter += min(m2[it->first], it->second);
        uni += max(m2[it->first], it->second);
    }

    for (auto it = m2.begin(); it != m2.end(); it++)
    {
        if (m1[it->first] == 0)
            uni += it->second;
    }

    if (v1.empty() && v2.empty())
        answer = 1 * 65536;
    else
        answer = inter / uni * 65536;

    return answer;
}