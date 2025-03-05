#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]==nums[i+1]){
                    nums[i] = nums[i]*2;
                    nums[i+1] = 0;
                }
            }
            int index = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    nums[index++] = nums[i];
                }
            }
            
            for(int i = index ; i<nums.size();i++){
                nums[i] = 0;
            }
    
    
            //should be two pointer approach
    
    
            // int index = 0;
            // vector<int>ans(nums.size());
            // for(int i=0;i<nums.size();i++){
            //     if(nums[i]!=0){
            //         ans[index] = nums[i];
            //         index++;
            //     }
            // }
    
            // return ans;
    
            return nums;
        }
    };