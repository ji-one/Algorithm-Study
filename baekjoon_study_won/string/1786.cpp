#include <iostream>
#include <string>
#include <vector>
using namespace std;
// solution
// kmp algorithm
vector<int> res;
vector<int> makeTable(string pattern)
{
    int patternSize = pattern.size();
    vector<int> fail(patternSize, 0);
    int j = 0;
    for (int i = 1; i < patternSize; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = fail[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            fail[i] = ++j;
        }
    }
    return fail;
}

void kmp(string parent, string pattern)
{
    vector<int> fail = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();

    int j = 0;

    for (int i = 0; i < parentSize; i++)
    {
        while (j > 0 && pattern[j] != parent[i])
        {
            j = fail[j - 1];
        }
        if (pattern[j] == parent[i])
        {
            if (j == patternSize - 1)
            {
                res.push_back(i - patternSize + 2);
                j = fail[j];
            }
            else
                ++j;
        }
    }
}

int main()
{
    string t, p;

    getline(cin, t);
    getline(cin, p);

    kmp(t, p);

    cout << res.size() << '\n';
    for (auto n : res)
        cout << n << '\n';
}