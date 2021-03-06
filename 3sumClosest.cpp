/*
https://www.interviewbit.com/old/problems/3-sum/
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution*/

int Solution::threeSumClosest(vector<int> &A, int B) {

    long long int res=INT_MAX;
int i,ans;
sort(A.begin(),A.end());
for(i=0;i<A.size()-1;i++)
{
int l=i+1;
int r=A.size()-1;
while(l<r)
{
long long int sum=long(A[i])+long(A[l])+long(A[r]);
if(sum-B==0)
{
l++;
r--;
}
else if(sum<B)
{
l++;
}
else
{
r--;
}
if(abs(sum-B)<res)
{
res=abs(sum-B);
ans=sum;
}
}
}
return ans;
}
