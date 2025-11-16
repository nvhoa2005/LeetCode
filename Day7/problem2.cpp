#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l_first = 0, r_first = n-1;
        int l_second = 0, r_second = n-1;
        int res_left = -1, res_right = -1;
        while(l_first <= r_first){
            int m = (l_first + r_first)/2;
            if(nums[m] == target){
                res_left = m;
                r_first--;
            } else if(nums[m] < target){
                l_first++;
            } else{
                r_first--;
            }
        }
        while(l_second <= r_second){
            int m = (l_second + r_second)/2;
            if(nums[m] == target){
                res_right = m;
                l_second++;
            } else if(nums[m] < target){
                l_second++;
            } else{
                r_second--;
            }
        }
        vector<int> result = {res_left, res_right};
        return result;
    }
};