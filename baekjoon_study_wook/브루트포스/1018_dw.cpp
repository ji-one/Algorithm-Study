//1018 체스판 다시 칠하기
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;
string arr[51];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

int chess(int x, int y){
    int num1=0;
    int num2=0;

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(arr[x+i][y+j] != BW[i][j])
                num1++;
        }
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(arr[x+i][y+j] != WB[i][j])
                num2++;
        }
    }
    
    // cout << num1 << ' ' << num2 << '\n';
    return min(num1,num2);
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int rst=64;
    for(int i=0; i<n-7; i++){
        for(int j=0; j<m-7; j++){
            rst = min(rst,chess(i,j));
            
        }
    }
    cout << rst;
    return 0;
}