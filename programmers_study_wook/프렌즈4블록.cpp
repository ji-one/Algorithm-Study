// 2018 카카오
#include <string>
#include <vector>
#include <iostream>
using namespace std;


vector<pair<int, int>> rm;
   
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(1){
        rm.clear();
        
        // 지울 수 있는 위치 저장
        bool exit=true;
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                
                char c = board[i][j];
                if(c=='0') continue;
                if(board[i+1][j+1] == c && 
                        board[i+1][j] == c&& board[i][j+1] == c){
                    exit= false;
                    rm.push_back({i,j});
                }
            }
        }
        if(exit) break; // 없으면 종료
        
        
        // 지울 수 있는 블럭 제거 + 개수 세기
        for(int i=0; i<rm.size(); i++){
            int x = rm[i].first;
            int y = rm[i].second;
            for(int j=x; j<x+2; j++){
                for(int k=y; k<y+2; k++){
                    if(board[j][k] != '0'){
                        answer++;
                        board[j][k] = '0';
                    }
                }
            }
        }

        // 빈공간 채우기
        for(int j=0; j<n; j++){
            
            for(int i=m-1; i>=0;i--){
                int x=-1; // 빈공간이 아닌 위치 저장
                if(board[i][j] == '0') {
                    x=i;
                    bool flag = false;
                    
                    while(1){
                        // 빈공간이 아닌 블럭을 찾으면 종료
                        if(board[i][j] != '0'){
                            flag = true;
                            break;
                        }                    
                        if(i == 0) break;
                        i--;
                    }
                    if(flag){
                        board[x][j] = board[i][j];
                        board[i][j] = '0';
                        i=x;
                    }

                }
            }
        }
        
        
    }
    
    
    
    
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    return answer;
}