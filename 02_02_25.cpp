#include<iostream>
#include<vector>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
//         vector<vector<int>>ans;
//         int i=0;
//         int j=0;
//         while(i<nums1.size() && j<nums2.size()){
//             vector<int>v(2,0);
//             if(nums1[i][0]==nums2[j][0]){
//                 v[0] = nums1[i][0];
//                 v[1] = nums1[i][1]+nums2[j][1];
//                 ans.push_back(v);
//                 i++;
//                 j++;
//             }else if(nums1[i][0] > nums2[j][0]){
//                     v[0] = nums2[j][0];
//                      v[1] = nums2[j][1];
//                     ans.push_back(v);
//                     j++;
//             }else if(nums1[i][0] < nums2[j][0]){
//                     v[0] = nums1[i][0];
//                     v[1] = nums1[i][1];
//                     ans.push_back(v);
//                     i++;
//             }

//             }
//             while(i<nums1.size()){
//                 vector<int>v(2);
//                  v[0] = nums1[i][0];
//                     v[1] = nums1[i][1];
//                 ans.push_back(v);
//                 i++;
//             }
//             while(j<nums2.size()){
//                 vector<int>v(2);
//                  v[0] = nums2[j][0];
//                  v[1] = nums2[j][1];
//                     ans.push_back(v);
              
//                 j++;
//             }
//             return ans;
//         }
//     };

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            vector<vector<int>>ans;
            int temp1=0, temp2=0;
            int n1 = nums1.size(), n2 = nums2.size();
            while(temp1<n1 && temp2<n2){
                if(nums1[temp1][0]==nums2[temp2][0]){
                    ans.push_back({nums1[temp1][0],nums1[temp1][1]+nums2[temp2][1]});
                    temp1++;temp2++;
                }
                else if(nums1[temp1][0]<nums2[temp2][0]){
                    ans.push_back({nums1[temp1][0],nums1[temp1][1]});
                    temp1++;               
                }
                else{
                    ans.push_back({nums2[temp2][0],nums2[temp2][1]});
                    temp2++;                
                }
            }
    
            while(temp1<n1){
                ans.push_back({nums1[temp1][0],nums1[temp1][1]});
                temp1++; 
            }
    
            while(temp2<n2){
                ans.push_back({nums2[temp2][0],nums2[temp2][1]});
                temp2++; 
            }
            return ans; 
        }
    };