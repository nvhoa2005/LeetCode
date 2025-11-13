#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < n; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n; j++){
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                int l = j+1, r = n-1;
                while(l < r){
                    ll tmp = 1ll*nums[i] + 1ll*nums[j] + 1ll*nums[l] + 1ll*nums[r];
                    if(tmp == target){
                        vector<int> res = {nums[i], nums[j], nums[l], nums[r]};
                        result.push_back(res);
                        l++;
                        while(l < r && nums[l] == nums[l-1]){
                            l++;
                        }
                    } else if(tmp < target){
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
        }
        return result;
    }
};