/*
솔루션 봄
시간 초과 -> 이분탐색으로 가능한지 생각해봄
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int MAX = 200000000;
int max_val;
bool check(int m, vector<int> stones, int k){
    int jump=0;
    for(int i=0; i<stones.size(); i++){
        
        if(stones[i]-(m-1)<=0){ // 0이므로 다음 다리 건넘
            jump++;
            if(k == jump){
                return false;
            }
        }
        else{
            jump=0;
        }
    }
    
    
    return true;
}
void binarySearch(int start, int end, vector<int> stones, int k){
    int left = start;
    int right = end;
    
    while(left<=right){
        int mid = (left+right)/2;
        bool go = check(mid, stones,k);
        // m 명이 건널 수 있다면
        if(go){
            max_val = mid;
            left = mid+1;
        }
        // m 명이 건널 수 없다면
        else{
            right = mid-1;
        }
    }
}
int solution(vector<int> stones, int k) {
    int answer = 0;

    binarySearch(0,MAX,stones,k);
    answer = max_val;
    return answer;
}