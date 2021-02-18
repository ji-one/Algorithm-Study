/*
    솔루션 봄
    n개의 원반을 옮긴다고 하면, 1번 기둥에 있는 n-1개의 원반을 2번 기둥으로 옮기고, 
    1번 기둥에 남아 있는 가장 큰 원반을 3번 기둥으로 옮겨줍니다. 
    또한 2번 기둥에 있는 n-1개의 원반을 3번 기둥으로 옮기면 됩니다.

    (1) 원반이 한개일 경우 그냥 3번으로 옮겨주면 됩니다(종료 조건)

    (2) 원반이 n개일 경우

       ① 1번 기둥에 있는 n개의 원반 중 n-1개를 2번 기둥으로 옮깁니다.(3번 기둥을 거쳐감)

       ② 1번 기둥에 남아 있는 가장 큰 원반을 3번 기둥으로 옮깁니다.

       ③ 2번 기둥에 있는 n-1개의 원반을 다시 3번 기둥으로 옮깁니다.(1번 기둥을 거쳐감)
*/

#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void hanoi(int n, int start, int end, int mid){
    // 가장 큰 원판을 1 -> 3으로 옮긴다.
    if(n==1) {
        answer.push_back({start,end});
        return ;
    }
    // n-1 원판을 1->2 옮긴다.
    hanoi(n-1,start,mid,end);
    answer.push_back({start,end});
    // n-1 원판을 2->3 옮긴다.
    hanoi(n-1,mid,end,start);
}

vector<vector<int>> solution(int n) {
    //     시작, 끝, 거쳐가는 원판
    hanoi(n,1,3,2);
    return answer;
}