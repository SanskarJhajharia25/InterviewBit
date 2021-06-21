// https://www.interviewbit.com/old/problems/distinct-numbers-in-window/
/*

Problem Description

You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

NOTE: if B > N, return an empty array.
*/

vector<int> Solution::dNums(vector<int> &A, int B) 
{
  map<int,int> m;
  vector<int> sol;
  for(int i=0;i<B;++i)
    m[A[i]]++;
  sol.push_back(m.size());
  int j=B;
  int i=0;
  while(j<A.size())
  {
    if(m[A[i]]==1)
      m.erase(A[i]);
    else
      m[A[i]]--;
    i++;
    m[A[j]]++;
    sol.push_back(m.size());
    j++;  
  }
  return sol;
}
