// 2022 사다리
// 솔루션 봄
/*
    삼각형 길이의 비 이용 
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double x, y, c;
double rst;
double func(double w){
    double h1 = sqrt(x*x - w*w);
    double h2 = sqrt(y*y - w*w);

    return (h1*h2)/(h1+h2);
}
void binarySearch(double start, double end){
    double left = start;
    double right = end;
    while(right - left > 0.000001){
        double mid = (left + right)/2.0;
        if(func(mid) >= c){
            left = mid;
            rst = mid;
        }
        else{
            right = mid;
        }
    }
}
int main(){

    cin >> x >> y >> c;
    binarySearch(0, min(x,y));
    // cout << rst;
    printf("%0.3lf",rst);
    return 0;
}