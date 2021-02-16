#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
// solution
stack<pair<int, int>> st;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, x;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        while (!st.empty())
        {
            // 스택의 top이 현재 입력값보다 크면 신호 수신 가능
            if (st.top().second > x)
            {
                cout << st.top().first << ' ';
                break;
            }
            st.pop();
        }
        if (st.empty())
            cout << "0 ";
        st.push({i, x});
    }

    return 0;
}