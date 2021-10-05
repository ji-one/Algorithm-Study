#include <string>
#include <vector>

using namespace std;

void func(int type, int r1, int c1, int r2, int c2, int degree, vector<vector<int>>& board) {
    if(type==1) degree = 0-degree;
    for(int i=r1; i<=r2; i++) {
        for(int j=c1; j<=c2; j++) {
            board[i][j] += degree;
        }
    }
}
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();

    for(vector<int> s : skill) {
        int type = s[0];
        int r1 = s[1], c1 = s[2];
        int r2 = s[3], c2 = s[4];
        int degree = s[5];

        func(type, r1, c1, r2, c2, degree, board);

    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] > 0) answer++;
        }
    }
    return answer;
}