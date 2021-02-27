//1786 찾기
/*
     솔루션 봄
     KMP 알고리즘
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string t,p;
int fail[1000001];  // fail(j)  접두사와 접미사가 일치하는 길이.
vector<int> rst;

int main(){
     getline(cin,t);
     getline(cin,p);
     int n = t.size();
     int m = p.size();

     // 실패함수 구하는 법
     for(int i=1, j=0; i<m; i++){
          while(j>0 && p[i] != p[j]) j = fail[j-1];
          if(p[i] == p[j]) fail[i] = ++j;
     }

     for(int i=0, j=0; i<n; i++){
          // 현재 글자가 불일치하면 fail값을 따라간다.
          while(j>0 && t[i]!=p[j]) j = fail[j-1];
          // 현재 글자가 일치
          if(t[i] == p[j]){
               // p를 t[i:i+m-1] 에서 찾음
               if(j == m-1){
                    // 문제는 i가 1부터 시작이기때문에 시작지점에 1을 더해준다.
                    rst.push_back(i-m+1 +1);
                    j = fail[j];
               }
               else
                    j++;
          }
     }

     cout << rst.size() << '\n';
     for(int i=0; i<rst.size(); i++){
          cout << rst[i] << ' ';
     }
     return 0;
}