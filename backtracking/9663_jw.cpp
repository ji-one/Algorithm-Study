#include <iostream>
using namespace std;
int n;
int cnt;
int board[15]; // board[i] = j : i행 j열에 퀸 놓을 수 있음
bool promising(int row)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == board[row] || abs(board[i] - board[row]) == (row - i))
        {
            return false;
        }
    }
    return true;
}
void n_queen(int row)
{
    if (row == n)
    {
        ++cnt;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        board[row] = i;
        if (promising(row))
        {
            n_queen(row + 1);
        }
    }
}
int main()
{
    cin >> n;
    n_queen(0);
    cout << cnt;
    return 0;
}