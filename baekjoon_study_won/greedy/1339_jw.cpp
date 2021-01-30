#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int alpha[30];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            alpha[s[j] - 'A'] += pow(10, s.length() - j - 1);
        }
    }
    sort(alpha, alpha + 26, greater<int>());

    int total = 0;
    int num = 9;
    for (int i = 0; i < 26; i++)
    {
        total += alpha[i] * (num);
        --num;
    }
    cout << total;
}