// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<unordered_set>
// #include<algorithm>
// #include<set>
// #include<limits.h>
// using namespace std;

// class Solution {
//     public:
//         int countPaths(int n, vector<vector<int>>& roads) {
//             // yeh to confirm hai path pahuchenga hi 
//             // min ans is 1 shortest itself
//             //djikstra's implementation to find the shortest path 
//             const int MOD = 1e9 + 7;
//             unordered_map<int ,vector<pair<int , long long>>>adj;
//             for(int i=0;i<roads.size();i++){
//                 int f = roads[i][0];
//                 int s = roads[i][1];
//                 long long  w = roads[i][2];
    
//                 adj[f].push_back({s,w});
//                 adj[s].push_back({f,w});
//             }
    
//             set<pair<long long,int>>st;
//             vector<long long>dist(n,LLONG_MAX);
//             vector<int>way(n,0);
//             int src = 0;
//             dist[src] = 0;
//             way[src] = 1;
//             //the first one is the weight and the other is node;
//             st.insert({0,src});
//             while(!st.empty()){
//                 auto [currentWeight, currentNode] = *st.begin();
//                 st.erase(st.begin());
    
//                 for(const auto& node : adj[currentNode]){
//                     int nextNode = node.first;
//                     long long  nextWeight = node.second;
//                     long long newDist = 1LL * currentWeight + nextWeight;
    
//                     if(newDist < dist[nextNode]){
//                         st.erase({dist[nextNode], nextNode}); 
//                         dist[nextNode] = newDist;
//                         way[nextNode] = way[currentNode];
//                         st.insert({newDist, nextNode});
//                     }else if (newDist == dist[nextNode]) {
//                         way[nextNode] = (way[nextNode] + way[currentNode]) % MOD;
//                     }
//                 }
//             }  
            
//             return way[n-1];
//         }
//     };