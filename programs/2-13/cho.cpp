#include <iostream>
using namespace std;

int main(){
    long long cnt;
    long long coupon = 0;
    long long n = 0;
    while (cin >> cnt){
        coupon = cnt;
        while (coupon / 7){
            cnt += coupon / 7;
            coupon = coupon / 7 + coupon % 7;
        }
        cout << cnt << endl;
    }
    return 0;
}
