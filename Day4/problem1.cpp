#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closest = 100000;
        int result = 0;
        for(int i = 0; i < n; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l < r){
                int tmp = nums[i] + nums[l] + nums[r];
                if(closest > abs(target-tmp)){
                    closest = abs(target-tmp);
                    result = tmp;
                }
                if(tmp-target == 0) return target;
                else if(tmp - target < 0){
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