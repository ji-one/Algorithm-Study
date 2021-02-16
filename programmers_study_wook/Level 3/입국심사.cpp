/*
    이분탐색
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long binarySearch(long long start, long long end, int n, vector<int> times){
    long long rst=end;
    long long left = start;
    long long right = end;
    while(left<=right){
        long long mid = (left+right)/2;
        long long num = 0;
        for(int i=0; i<times.size(); i++){
            num += (mid/times[i]);
        }
        if(num>=n){
            rst = min(rst, mid);
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return rst;
}


long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long max_time = 0;
    for(int i=0; i<times.size(); i++){
        max_time = max(max_time, (long long)n*times[i]);
    }
    answer = binarySearch(0,max_time,n, times);
    
    return answer;
}