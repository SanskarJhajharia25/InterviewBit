/*

https://leetcode.com/problems/number-of-provinces/submissions/

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

*/

class Solution {
public:
    void dfs(int s,vector<vector<int>>& v, vector<bool>& vis){
        vis[s] = true;
        for(int x:v[s])
            if(vis[x]==false)
                dfs(x,v,vis);
    }
    
    // main function
    int findCircleNum(vector<vector<int>>& g) {
        
        // first make it a graph data structure
        int n = g.size();
        vector<vector<int>> v(n,vector<int>());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        
        // then traverse the graph and increase ans by 1 when any unvisited node is found
        vector<bool> vis(n,false);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                ans++;
                dfs(i,v,vis);
            }
        }
        return ans;
    }
};
