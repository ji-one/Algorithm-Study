#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        deque<int> dq;
        string p, arr;
        cin >> p;
        int n;
        cin >> n >> arr;
        string num = "";
        for (int i = 0; i < arr.length(); i++)
        {
            if (arr[i] >= '0' && arr[i] <= '9')
            {
                num += arr[i];
            }
            else if (arr[i] == ']' || arr[i] == ',')
            {
                if (num.length() != 0)
                {
                    dq.push_back(stoi(num));
                    num = "";
                }
            }
        }
        bool isReverse = false;
        bool isError = false;
        for (int i = 0; i < p.length(); i++)
        {
            if (p[i] == 'R')
            {
                isReverse = !isReverse;
            }
            if (p[i] == 'D')
            {
                if (dq.empty())
                {
                    isError = true;
                    break;
                }
                else
                {
                    if (isReverse)
                    {
                        dq.pop_back();
                    }
                    else
                    {
                        dq.pop_front();
                    }
                }
            }
        }
        if (isError)
        {
            cout << "error\n";
        }
        else
        {
            cout << "[";
            while (!dq.empty())
            {
                if (!isReverse)
                {
                    cout << dq.front();
                    dq.pop_front();
                }
                else
                {
                    cout << dq.back();
                    dq.pop_back();
                }
                if (!dq.empty())
                    cout << ",";
            }
            cout << "]\n";
        }
    }
}