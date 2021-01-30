#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int a[100001];
vector<int> solution(string s)
{
    vector<int> answer;

    for (int i = 0; i <= s.length(); i++)
    {
        string num = "";
        while (s[i] >= '0' && s[i] <= '9')
        {
            num += s[i];
            ++i;
        }
        if (num != "")
        {
            a[stoi(num)]++;
        }
    }
    vector<pair<int, int>> v;
    for (int i = 1; i <= 100000; i++)
    {
        if (a[i] != 0)
        {
            v.push_back({a[i], i});
        }
    }
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        answer.push_back(v[i].second);
    }
    return answer;
}