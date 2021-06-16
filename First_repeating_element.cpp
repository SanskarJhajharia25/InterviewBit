// https://www.interviewbit.com/problems/first-repeating-element/

/*
Given an integer array A of size N, find the first repeating element in it.

We need to find the element that occurs more than once and whose index of first occurrence is smallest.

If there is no repeating element, return -1.
*/

int Solution::solve(vector<int> &A) 
{
    map<int,int>mp; //stores the frequency of each possible value

    for(int i=0;i<A.size();i++)
      mp[A[i]]++;

    for(int i=0;i<A.size();i++)
      if(mp[A[i]]>1) //finding smallest index
        return A[i];

    return -1;
}
