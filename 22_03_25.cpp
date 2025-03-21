#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            //  do baar loop chalana hai kyuki baad mai koi dish ban gyi to pahele vali bhi ban jayegi;
            vector<string>ans;
            unordered_map<string,bool>pre;
            for(auto i : supplies){
                pre[i] = true;
            }
            bool a = true;
            while(a){
                a = false;
            for(int i=0;i<recipes.size();i++){
                string make = recipes[i];
                bool check = false;
                if(pre.find(make)!=pre.end()){
                    continue;
                }
                for(int j=0;j<ingredients[i].size();j++){
                    if(pre.find(ingredients[i][j]) == pre.end()){
                        check = true;
                        break;
                    }
                }
                if(!check){
                pre[make] = true;
                ans.push_back(make);
                a = true;
                }
            }
            }
            vector<string> anss = {ans.begin(), ans.end()};
            return anss;
        }
    };