#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < n; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l < r){
                int tmp = nums[i] + nums[l] + nums[r];
                if(tmp == 0){
                    vector<int> res = {nums[i], nums[l], nums[r]};
                    result.push_back(res);
                    l++;
                    while(l < r && nums[l] == nums[l-1]){
                        l++;
                    }
                } else if(tmp < 0){
                    l++;
                    while(l < r && nums[l] == nums[l-1]){
                        l++;
                    }
                } else {
                    r--;
                    while(l < r && r != n-1 && nums[r] == nums[r+1]){
                        r--;
                    }
                }
            }
        }
        return result;
    }
};