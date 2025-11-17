#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp = nums1;
        int l = 0, r = 0;
        int cnt = 0;
        while(l < m && r < n){
            if(tmp[l] <= nums2[r]){
                nums1[cnt++] = tmp[l++];
            } else{
                nums1[cnt++] = nums2[r++];
            }
        }
        while(l < m){
            nums1[cnt++] = tmp[l++];
        }
        while(r < n){
            nums1[cnt++] = nums2[r++];
        }
    }
};