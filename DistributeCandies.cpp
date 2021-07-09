// https://www.interviewbit.com/problems/distribute-candy/
/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Input Format:

The first and the only argument contains N integers in an array A.
Output Format:

Return an integer, representing the minimum candies to be given.
*/

int Solution::candy(vector<int> &A) {
    
    int n=A.size();
if(n==0){
return n;
}
vector<int> candy(n,1);//array with one candy to each child.
for(int i=1;i<n;i++)//forward loop
{
if(A[i]>A[i-1]&&candy[i]<=candy[i-1])//if current rating is higher than previous rating
{
candy[i]=1+candy[i-1];
}
}
for(int i=n-2;i>=0;i--)//backward loop
{
if(A[i]>A[i+1]&&candy[i]<=candy[i+1])//if currernt rating is lower than the rating of the child after
{
candy[i]=1+candy[i+1];
}
}
// for(int i=0;i<n;i++){
// cout<<A[i]<<" “;
// }
// cout<<endl;
// for(int i=0;i<n;i++){
// cout<<choco[i]<<” ";

// }
int sum=0;
for(int i=0;i<n;i++)
    sum+=candy[i];
return sum;
}
