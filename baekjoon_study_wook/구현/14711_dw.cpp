// 14711 타일 뒤집기

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string s;
int arr[1001][1001];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool isInside(int x, int y)  {
    return x>=0 && x<n && y>=0 && y<n;
}

void reverse(int x, int y) {
    arr[x][y] = 1 - arr[x][y];
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isInside(nx, ny)) {
            arr[nx][ny] = 1 - arr[nx][ny];
        }
        
    }
}
int main() {
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        if(s[i] == '#') {
            
            reverse(0, i);
        }

    }
    vector<int> idx;
    for(int i=1; i<n; i++) {
        
        for(int j=0; j<n; j++) {
            if(arr[i][j] ^ arr[i-1][j] == 1) {
                idx.push_back(j);
            }
        }

        for(int j=0; j<idx.size(); j++) {
            reverse(i, idx[j]);
        }

        idx.clear();
        
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == 0)
                cout << '.';
            else 
                cout << '#';
        }
        cout << '\n';
    }
    return 0;
}