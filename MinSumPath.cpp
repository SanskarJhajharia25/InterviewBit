// https://www.interviewbit.com/old/problems/min-sum-path-in-matrix/
/*
Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.

NOTE: You can only move either down or right at any point in time.
*/

int Solution::minPathSum(vector<vector<int> > &A) {
     int m = A.size(), n = A[0].size(), dp[m][n];
    for(int i=m-1; i>=0; i--)
        for(int j=n-1; j>=0; j--)
            if(i==m-1 && j==n-1) dp[i][j] = A[i][j];
            else if(i==m-1) dp[i][j] = A[i][j] + dp[i][j+1];
            else if(j==n-1) dp[i][j] = A[i][j] + dp[i+1][j];            
            else dp[i][j] = A[i][j] + min(dp[i+1][j], dp[i][j+1]);
    return dp[0][0];
}

