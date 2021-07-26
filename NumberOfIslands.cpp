/*

https://leetcode.com/problems/number-of-islands/

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

class Solution {
public:
     bool isValid(int i, int j, int row, int col){
        if( (i>=0 && i<row) && (j>=0 && j<col))
            return true;
        return false;
    }
    
    void bfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> &grid){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        
        while(!q.empty()){    
            i = q.front().first;
            j = q.front().second;
            q.pop();                   
// right
            if(isValid(i, j+1, m, n) && !visited[i][j+1] && grid[i][j+1]=='1'){ 
                q.push({i,j+1});
                visited[i][j+1]=1;
            }
// down
            if(isValid(i+1, j, m, n) && !visited[i+1][j] && grid[i+1][j]=='1'){ 
                q.push({i+1,j});
                visited[i+1][j]=1;
            }
// left
           if(isValid(i, j-1, m, n) && !visited[i][j-1] && grid[i][j-1]=='1'){ 
                q.push({i,j-1});
                visited[i][j-1]=1;
            }
            
// // up
            if(isValid(i-1, j, m, n) && !visited[i-1][j] && grid[i-1][j]=='1'){ 
                q.push({i-1,j});
                visited[i-1][j]=1;
            }
        }
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n,0));
        
        int no_of_island = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    bfs(i,j, visited, grid);
                    no_of_island++;
                }
            }
        }
        
        return no_of_island;
    }
};
