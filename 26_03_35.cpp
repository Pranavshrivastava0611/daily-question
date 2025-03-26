#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int>v;
            for(auto i : grid){
                for(auto j : i){
                    v.push_back(j);
                }
            }
            sort(v.begin(),v.end());
            int count = 0;
            int target = v.size()/2;
            int num = v[target];
            for(int i=0;i<v.size();i++){
                int check = abs(v[i]-num);
                if(check%x!=0){
                    return -1;
                }else{
                    count+=(check/x);
                }
            }
            return count;
        }
    };