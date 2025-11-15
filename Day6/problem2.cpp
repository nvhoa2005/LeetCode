#include <iostream>
#include <string>
using namespace std;

using ll = long long;
class Solution {
public:
    string strip(string s){
        string result = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            else{
                for(int j = i; j < s.size(); j++){
                    result += s[j];
                }
                return result;
            }
        }
        return result;
    }
    bool check_is_digit(char c){
        if((c-'0' >= 0) && (c-'0' <= 9)) return true;
        return false;
    }
    int myAtoi(string s) {
        s = strip(s);
        int n = s.size();
        bool check_sign = true;
        bool check_meet = false;
        ll res = 0;
        for(int i = 0; i < n; i++){
            if(check_meet){
                if(!check_is_digit(s[i])) break;
                res = res*10 + (s[i]-'0');
                if(res > INT_MAX){
                    break;
                }
            } else {
                check_meet = true;
                if(s[i] == '-') check_sign = false;
                else if(s[i] == '+') check_sign = true;
                else if(check_is_digit(s[i])){
                    res = res*10 + (s[i]-'0');
                    if(res > INT_MAX){
                        break;
                    }
                }
                else break;
            }
        }
        if(!check_sign) res = -res;
        if(res > INT_MAX) return INT_MAX;
        if(res < INT_MIN) return INT_MIN;
        return int(res);
    }
};