using ll = long long;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        ll x_tmp = x, reverse = 0;
        while(x_tmp){
            int du = x_tmp%10;
            reverse = reverse*10 + du;
            x_tmp/=10;
        }
        if(reverse != x) return false;
        return true;
    }
};