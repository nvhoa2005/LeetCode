#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ll tmp = 1;
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                cnt++;
                if(cnt == 2){
                    tmp = 0;
                    break;
                }
                continue;
            }
            tmp *=nums[i];
        }
        vector<int> result;
        for(int i = 0; i < n; i++){
            if(cnt == 0){
                result.push_back(tmp/nums[i]);
            } else {
                if(nums[i] == 0){
                    result.push_back(tmp);
                } else {
                    result.push_back(0);
                }
            }
        }
        return result;
    }
};

// Tích của mảng trừ chính nó là tích của các phân tử bên trái nhân với tích của các phần tử bên phải.
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        ll left = 1, right = 1;
        vector<int> result(n, 1);
        for(int i = 0; i < n; i++){
            result[i] = left;
            left *= nums[i];
        }
        for(int i = n-1; i >= 0; i--){
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};