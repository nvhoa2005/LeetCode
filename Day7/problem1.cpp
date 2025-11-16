#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] == target) return 0;
            return -1;
        }
        int flag = -1;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                flag = i;
                break;
            }
        }
        if(flag == -1) flag = n;
        int l, r;
        if(target >= nums[0]){
            l = 0, r = flag-1;
        } else {
            l = flag, r = n-1;
        }
        while(l <= r){
            int m = (l+r)/2;
            if(nums[m] == target){
                return m;
            } else if(nums[m] < target){
                l++;
            } else {
                r--;
            }
        }
        return -1;
    }
};