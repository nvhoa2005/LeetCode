#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0] > 0 ? nums[0] : 0;
        int res = nums[0] > 0 ? nums[0] : 0;
        int max_array = nums[0];
        for(int i = 1; i < n; i++){
            max_array = max(max_array, nums[i]);
            res += nums[i];
            if(res < 0){
                res = 0;
            } else {
                result = max(result, res);
            }
        }
        if(result <= 0) return max_array;
        return result;
    }
};