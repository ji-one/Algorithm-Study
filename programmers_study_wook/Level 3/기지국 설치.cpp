/*
 solution
 그리디
 1 번 기지국 부터 설치가 가능한지 확인한다.
 설치할 필요가 없으면(영역안이면) 현재영역 맨 끝으로 옮긴다.
 설치할 필요가 있으면 설치를 하고, 2*w 만큼 옮긴다.
*/
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    // 기지국 번호  기지국 인덱스
    int num = 1, idx=0;
    
    while(num<=n){
        if(num >= stations[idx] - w && num <= stations[idx] + w){
            num = stations[idx] + w;
            idx++; // 다음 기지국
        }
        else{
            num += 2*w;
            answer++;
        }
        num++;
    }

    return answer;
}