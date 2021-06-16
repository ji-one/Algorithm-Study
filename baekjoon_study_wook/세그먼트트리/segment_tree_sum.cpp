// 세그먼트 트리 Segment Tree
// 특정 구간의 합의 예

#include <iostream>
#include <vector>
#define NUMBER 12

using namespace std;

int a[] = {1,9,3,8,4,5,5,9,10,3,4,5};
int tree[4*NUMBER]; // 4를 곱하면 모든 범위를 커버할 수 있다.

// start : 시작 인덱스, end : 끝 인덱스
int init(int start, int end, int index) {
    if(start == end) return tree[index] = a[start];
    int mid = (start+end)/2;
    return tree[index] = init(start, mid, index*2) + init(mid+1,end, index*2+1);

}

// start : 시작 인덱스, end : 끝 인덱스
// left, right : 구간 합을 구하고자 하는 범위
int sum(int start, int end, int index, int left, int right) {
    // 범위 밖에 있는 경우
    if(left > end || right < start) return 0;
    // 범위 안에 있는 경우
    if(left <= start && right >= end)
        return tree[index];
    int mid = (start + end) / 2;
    return sum(start, mid, index *2, left, right) + sum(mid+1, end, index*2+1, left, right);
}

void update(int start, int end, int index, int changeIndex, int diff) {
    // 범위 밖에 있는 경우
    if(changeIndex < start || changeIndex > end) return ;
    // 범위 내에 있는 경우 갱신
    tree[index] += diff;
    if(start == end) return ;
    int mid = (start + end) / 2;

    update(start, mid, index * 2, changeIndex, diff);
    update(mid+1, end, index*2+1, changeIndex, diff);
}

int main() {

    init(0, NUMBER -1, 1);

    // 0~11 구간 합 구하기
    cout << "0~11 sum : " << sum(0, NUMBER-1, 1, 0, 11) << '\n';

    // 4~8 구간 합 구하기
    cout << "4~8 sum : " << sum(0, NUMBER-1, 1, 4, 8) << '\n';

    int val = 10; // 변경할 값
    int changeIndex = 2; // 변경할 인덱스
    int diff = val - a[changeIndex]; // 변경할 값의 차이
    update(0, NUMBER-1, 1, changeIndex, diff);

    // 0~11 구간 합 구하기
    cout << "0~11 sum : " << sum(0, NUMBER-1, 1, 0, 11) << '\n';

    // 4~8 구간 합 구하기
    cout << "4~8 sum : " << sum(0, NUMBER-1, 1, 4, 8) << '\n';

    return 0;
}