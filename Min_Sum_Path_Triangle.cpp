// https://www.interviewbit.com/old/problems/min-sum-path-in-triangle/
/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
*/

int Solution::minimumTotal(vector<vector<int> > &a) 
{
    int n = a.size();
    int cnt = a[n-2].size();

    for(int i = n - 2; i >= 0; i--)
    {
      for(int j = 0; j < cnt; j++)  
      {
        a[i][j] += min({ a[i+1][j], a[i+1][j+1] });
      }
    cnt--;
}
return a[0][0];
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
