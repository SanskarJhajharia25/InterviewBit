/*
https://leetcode.com/problems/where-will-the-ball-fall/submissions/

You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.

*/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
              
        vector<int> answers;
       
        for(int i=0;i<grid[0].size();i++){
            int ans = doDfs(grid,0,i);
            answers.push_back(ans);
        }    
            
    return answers; 
    }
   bool check(vector<vector<int>>& grid,int row,int col){
       if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size()){
           return false;
       }
       return true;
   } 
   int doDfs(vector<vector<int>>& grid,int row,int column) {
       
       if(row>grid.size()-1){
           return column;
       }
       
       if(!check(grid,row,column)){
           return -1;
       }
       
       if(grid[row][column]==1 && check(grid,row,column+1) && grid[row][column+1]==1){
          return doDfs(grid,row+1,column+1);
       }
       
       if(grid[row][column]==-1 && check(grid,row,column-1) && grid[row][column-1]==-1){
          return doDfs(grid,row+1,column-1);
       }

       return -1;
   } 
};
