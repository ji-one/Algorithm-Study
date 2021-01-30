#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a[51][51]; // m s d
int N, M, K;
int dir[8][2] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};

void step1()
{
    vector<int> tmp[51][51];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (!a[i][j].empty())
            {
                for (int k = 0; k < a[i][j].size(); k += 3)
                {
                    int m, s, d;
                    m = a[i][j][k];
                    s = a[i][j][k + 1];
                    d = a[i][j][k + 2];

                    int nc = j + s * dir[d][0];
                    int nr = i + s * dir[d][1];

                    while (nc < 1)
                        nc += N;

                    while (nr < 1)
                        nr += N;

                    while (nc > N)
                        nc -= N;

                    while (nr > N)
                        nr -= N;
                   
                    tmp[nr][nc].push_back(m);
                    tmp[nr][nc].push_back(s);
                    tmp[nr][nc].push_back(d);
                }
            }
            a[i][j].clear();
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k < tmp[i][j].size(); k++)
            {
                a[i][j].push_back(tmp[i][j][k]);
            }
        }
    }
}
void step2()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (a[i][j].size() >= 6)
            {
                int sum_m = 0;
                int sum_s = 0;
                vector<int> d;
                for (int k = 0; k < a[i][j].size(); k += 3)
                {
                    int m = a[i][j][k];
                    int s = a[i][j][k + 1];
                    d.push_back(a[i][j][k + 2]);
                    sum_m += m;
                    sum_s += s;
                }

                int num = a[i][j].size() / 3;
                sum_m /= 5;
                sum_s /= num;
                a[i][j].clear();

                if (sum_m == 0)
                    continue;

                int isNotSame = 0;
                for (int k = 0; k < d.size() - 1; k++)
                {
                    if (d[k] % 2 != d[k + 1] % 2)
                    {
                        isNotSame = 1;
                        break;
                    }
                }

                for (int k = 0; k < 4; k++)
                {
                    a[i][j].push_back(sum_m);
                    a[i][j].push_back(sum_s);
                    a[i][j].push_back(k * 2 + isNotSame);
                }
            }
        }
    }
}
int main()
{

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        a[r][c].push_back(m);
        a[r][c].push_back(s);
        a[r][c].push_back(d);
    }

    for (int i = 0; i < K; i++)
    {
        step1();
        step2();
    }

    int sum_m = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (!a[i][j].empty())
            {
                for (int k = 0; k < a[i][j].size(); k += 3)
                {
                    int m = a[i][j][k];
                    sum_m += m;
                }
            }
        }
    }
    cout << sum_m;
}