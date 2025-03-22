#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
    public:
      
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            int count = 0;
            unordered_map<int,vector<int>>adj;
            vector<int>indegree(n,0);
            for(int i=0;i<edges.size();i++){
                int f = edges[i][0];
                int s = edges[i][1];
                adj[f].push_back(s);
                adj[s].push_back(f);
            }
            vector<vector<int>>comp;
            unordered_map<int,bool>vis;
            queue<int>q;
            bool check = false;
            vector<int>store;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    if(check){
                        comp.push_back(store);
                        check = false;
                        store.clear();
                    }
                    vis[i] = true;
                    store.push_back(i);
                    q.push(i);
                    check = true;
                    while(!q.empty()){
                        auto top = q.front();
                        q.pop();
    
                        for(auto j : adj[top]){
                            indegree[j]++;
                            if(!vis[j]){
                                vis[j] = true;
                                q.push(j);
                                store.push_back(j);
                            }
                        }
                    }
                }
            }
    
            if(!store.empty()){
                comp.push_back(store);
                store.clear();
            }
           
           for(int i=0;i<comp.size();i++){
            bool check = true;
            for(int j=0;j<comp[i].size();j++){
                int length = comp[i].size();
                if(indegree[comp[i][j]]!=comp[i].size()-1){
                    check = false;
                }
            }
            if(check){
                count++;
            }
           }
            
            return count;
    
        }
    };