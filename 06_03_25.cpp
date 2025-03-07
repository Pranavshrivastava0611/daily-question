#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            unordered_map<int,int>m;
            int c = n*n ;
            int sum = (c*(c+1))/2;
            int loopSum = 0;
            for(auto i : grid){
                for(auto j : i){
                    loopSum += j;
                    m[j]++;
                }
            }
            int a = -1;
            for(auto i : m){
                if(i.second==2){
                    a = i.first;
                    break;
                }
            }
            cout<<a;
            loopSum = loopSum - a;
            int b = sum - loopSum;
            return {a,b};
        }
    };