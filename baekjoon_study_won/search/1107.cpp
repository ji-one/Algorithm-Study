#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
// solution 봄
int n, m, len;
int num[10];
int res = INT_MAX;
bool isPossible(int x)
{
    if (x == 0)
    {
        if (num[0] == 1)
        {
            return false;
        }
        else
            return true;
    }
    while (x)
    {
        if (num[x % 10] == 1)
            return false;
        x /= 10;
    }
    return true;
}
void solution(int x)
{
    int from100 = abs(x - 100);
    int tmp;
    for (int i = 0; i <= 1000000; i++)
    {
        if (isPossible(i))
        { // 누를 수 있는 번호
            tmp = to_string(i).length();
            tmp += abs(i - x); // +- 누르는 횟수
            res = min(res, tmp);
        }
    }
    res = min(from100, res);
}
int main()
{
    cin >> n >> m;
    // 채널 0에서 - 누르면 채널 안변함, 채널은 무한대
    // n으로 이동하기위해 버튼 몇번 눌러야하나
    int tmp = n;
    while (tmp > 0)
    {
        tmp /= 10;
        ++len;
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        num[x] = 1;
    }
    solution(n);
    cout << res;
    return 0;
}