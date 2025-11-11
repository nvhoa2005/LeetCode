#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool check(pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        pair<int, int> p[10001];
        for(int i = 0; i < n; i++){
            p[i].first = nums[i];
            p[i].second = i;
        }
        sort(p, p+n, check);
        int l = 0, r = n-1;
        vector<int> res;
        while(l < r){
            int tmp = p[l].first + p[r].first;
            if(tmp < target){
                l++;
            } else if(tmp > target){
                r--;
            } else {
                res.push_back(p[l].second);
                res.push_back(p[r].second);
                return res;
            }
        }
        return res;
    }
};