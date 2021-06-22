//https://www.interviewbit.com/problems/maximum-sum-combinations/
/*Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.
*/
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end(),greater());
sort(B.begin(),B.end(),greater());
vector<int> k;
int n=B.size();
for(int i=0;i<n/2 + n%2;i++)
{
for(int j=0;j<ceil((double)n/(i+1));j++)
{
k.push_back(A[i]+ B[j]);
}
}
for(int i=n/2 + n%2;i<n;i++)
{
k.push_back(A[i]+ B[0]);
}
sort(k.begin(),k.end(),greater());
vector<int> c;
for(int i=0;i<C;i++)
{
c.push_back(k[i]);
}
return c;
}
