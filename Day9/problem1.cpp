#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n+1, 0);
        for(int i = 0; i < n; i++){
            check[nums[i]]++;
            if(check[nums[i]] == 2){
                return nums[i];
            }
        }
        return 0;
    }
};