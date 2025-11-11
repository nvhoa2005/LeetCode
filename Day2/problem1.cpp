#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:

    bool check(char a, char b){
        if(a == '(' && b == ')') return true;
        if(a == '{' && b == '}') return true;
        if(a == '[' && b == ']') return true;
        return false;
    }
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            } else {
                if(st.empty()) return false;
                char top = st.top();
                if(!check(top, s[i])) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};