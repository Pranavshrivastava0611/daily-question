#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    private :
        static bool compare(vector<int>&a,vector<int>&b){
            return a[0] < b[0];
        }
        static bool compare2(vector<int>&a,vector<int>&b){
            return a[1] < b[1];
        }
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangle) {
            vector<vector<int>>x;
            vector<vector<int>>y;
            sort(rectangle.begin() , rectangle.end(),compare);
            int fx= rectangle[0][0];
            int sx = rectangle[0][2];
    
            for(int i=1;i<rectangle.size();i++){
                
                if(rectangle[i][0] < sx){
                    sx = max(sx,rectangle[i][2]);
                }else{
                    x.push_back({fx,sx});
                    fx = rectangle[i][0];
                    sx = rectangle[i][2];
                }
    
            }
            x.push_back({fx,sx});
    
            sort(rectangle.begin() , rectangle.end(),compare2);
            int fy = rectangle[0][1];
            int sy = rectangle[0][3];
    
            for(int i=1;i<rectangle.size();i++){
    
                if(rectangle[i][1] < sy){
                    sy = max(sy,rectangle[i][3]);
                }else{
                    y.push_back({fy,sy});
                    fy = rectangle[i][1];
                    sy = rectangle[i][3];
                }
            }
    
            y.push_back({fy,sy});
    
            if(x.size()>=3 || y.size()>=3){
                return true;
            }
    
            return false;
        }
    };