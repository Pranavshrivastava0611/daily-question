#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int index = 0;
            vector<int>ans(nums.size());
            for(int i=0;i<nums.size();i++){
                if(nums[i] < pivot){
                    ans[index++] = nums[i];
                }
            }
            for(int i=0;i<nums.size();i++){
                if(nums[i] == pivot){
                    ans[index++] = nums[i];
                }
            }
            for(int i=0;i<nums.size();i++){
                if(nums[i] > pivot){
                    ans[index++] = nums[i];
                }
            }
            return ans;
    
        }
    };