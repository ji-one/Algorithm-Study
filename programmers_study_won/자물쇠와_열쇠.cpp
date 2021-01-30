#include <string>
#include <vector>
#include <iostream>
using namespace std;
int m, n;
int lock_r, lock_c;
int lock_board[100][100];
int key_board[100][100];
bool isPossible = false;
bool check()
{
    for (int i = lock_r; i < lock_r + n; i++)
    {
        for (int j = lock_c; j < lock_c + n; j++)
        {
            if (lock_board[i][j] == key_board[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
void fill_key(int x, int y, vector<vector<int>> key)
{
    for (int i = y; i < y + m; i++)
    {
        for (int j = x; j < x + m; j++)
        {
            key_board[i][j] = key[i - y][j - x];
        }
    }

    isPossible = check();

    for (int i = y; i < y + m; i++)
    {
        for (int j = x; j < x + m; j++)
        {
            key_board[i][j] = 0;
        }
    }
}
void rotate(vector<vector<int>> &key)
{
    vector<vector<int>> tmp(m, vector<int>(m));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp[i][j] = key[m - j - 1][i];
        }
    }
    key = tmp;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = false;
    m = key.size();
    n = lock.size();

    lock_r = m - 1;
    lock_c = m - 1;
    for (int t = 0; t < 4; t++)
    {
        rotate(key);
        for (int i = m - 1; i < m - 1 + n; i++)
        {
            for (int j = m - 1; j < m - 1 + n; j++)
            {
                lock_board[i][j] = lock[i - (m - 1)][j - (m - 1)];
            }
        }

        for (int i = 0; i <= m + n - 2; i++)
        {
            for (int j = 0; j <= m + n - 2; j++)
            {
                fill_key(j, i, key);
                if (isPossible)
                {
                    answer = true;
                    return answer;
                }
            }
        }
    }

    return answer;
}