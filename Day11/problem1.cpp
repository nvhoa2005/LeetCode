#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        vector<int> res;
        res.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                cnt++;
            } else {
                res.push_back(nums[i]);
            }
        }
        nums = res;
        return n-cnt;
    }
};