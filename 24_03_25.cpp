#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    private : 
       static bool compare(vector<int>&a,vector<int>&b){
            return a[0] < b[0];
        }
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            vector<vector<int>>str;
            sort(meetings.begin(),meetings.end(),compare);
            int f = meetings[0][0];
            int s = meetings[0][1];
    
            for(int i=1;i<meetings.size();i++){
                if(meetings[i][0] <= s){
                    s = max(s,meetings[i][1]);
                }else{
                    vector<int>v(2);
                    v[1] = s;
                    v[0] = f;
                    str.push_back(v);
                    f = meetings[i][0];
                    s = meetings[i][1];
                }
            }
    
            str.push_back({f,s});
    
            int count = 0;
    
            if (str[0][0] > 1) {
                count += str[0][0] - 1;
            }
            for(int i=1;i<str.size();i++){
                count = count + str[i][0] - str[i-1][1]-1;
            }
            count+= days - str[str.size()-1][1];
            cout<<count;
            return count;
        }
    };

