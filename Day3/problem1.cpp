#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0, min_left = prices[0];
        for(int i = 1; i < n; i++){
            res = max(res, prices[i]-min_left);
            min_left = min(min_left, prices[i]);
        }
        return res;
    }
};