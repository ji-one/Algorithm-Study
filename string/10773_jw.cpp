#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int k;
    vector<int> v;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            v.pop_back();
        }
        else
        {
            v.push_back(n);
        }
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    
    cout << sum;
    return 0;
}