//https://www.interviewbit.com/problems/rain-water-trapped/

/*
Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
*/

int Solution::trap(const vector<int> &A) {
    vector<int> left(A.size());
    left[0] = A[0];
    for(int i=1;i<A.size();i++)
    {
        left[i] = max(left[i-1],A[i]);
    }
    
    //Max right height for each bar
    vector<int> right(A.size());
    right[A.size()-1] = A[A.size()-1];
    for(int i=A.size()-2;i>=0;i--)
    {
        right[i] = max(right[i+1],A[i]);
    }
    
    //Total trapped water
    //For each bar total trapped water will be min bar height to the left or right of it minus its height
    int trap = 0;
    for(int i=0;i<A.size();i++)
    {
        trap += min(left[i],right[i]) - A[i];
    }
    
    return trap;
}
