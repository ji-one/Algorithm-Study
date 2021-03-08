#include <iostream>
#include <queue>
#include <map>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> m;
        int k;
        cin >> k;
        while (k--)
        {
            char c;
            int n;
            cin >> c >> n;
            if (c == 'D' && m.size() != 0)
            {
                map<int, int>::iterator it;
                if (n == 1)
                    it = --m.end();

                if (n == -1)
                    it = m.begin();

                int num = it->first;
                if (m[num] == 1)
                    m.erase(num);
                else
                    --m[num];
            }
            if (c == 'I')
            {
                m[n]++;
            }
        }

        if (m.size() == 0)
            cout << "EMPTY\n";
        else
        {
            auto top = m.begin();
            auto back = --m.end();

            cout << back->first << ' ' << top->first << '\n';
        }
    }
    return 0;
}