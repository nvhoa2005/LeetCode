#include <iostream>
using namespace std;
using ll = long long;

class Solution {
public:
    int reverse(int x) {
        ll res = 0;
        ll tmp = abs(1ll * x);
        while (tmp) {
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }
        if (x < 0) res = -res;
        if (res < INT_MIN || res > INT_MAX) return 0;
        return (int)res;
    }
};
