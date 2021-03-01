#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    if(a>b){
        int tmp = b;
        b = a;
        a = tmp;
    } 
    while(n>1){
        // 둘이 만남.
        if((b-a == 1) && (b%2 == 0)) break;
        b = ceil((double)b/2);
        a = ceil((double)a/2);
        n/=2;
        answer++;
    }
    
    return answer;
}