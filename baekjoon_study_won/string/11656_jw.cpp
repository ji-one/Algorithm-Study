// 접미사 배열
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<string> v;

    for (int i = 0; i < s.length(); i++)
    {
        string suffix = "";
        for (int j = i; j < s.length(); j++)
        {
            suffix += s[j];
        }
        v.push_back(suffix);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << '\n';
    }
    return 0;
}