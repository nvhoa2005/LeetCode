#include <iostream>
using namespace std;
using ll = long long;

class Solution {
public:
    double myPow(double x, int n) {
        ll tmp = 1ll*n;
        if(tmp < 0) {
            x = 1 / x;
            tmp = -tmp;
        }
        return fastPow(x, tmp);
    }

private:
    double fastPow(double x, long long n) {
        if(n == 0) return 1;
        double half = fastPow(x, n / 2);
        if(n % 2 == 0){
            return half * half;
        } else{
            return half * half * x;
        }
    }
};
