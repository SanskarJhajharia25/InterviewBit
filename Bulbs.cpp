/*
https://www.interviewbit.com/problems/interview-questions/

N light bulbs are connected by a wire.

Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb.

Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs.

You can press the same switch multiple times.

Note : 0 represents the bulb is off and 1 represents the bulb is on.


*/

int Solution::bulbs(vector<int> &A) {
    int res=0;
int n=A.size();
int count=0;
for(int i=0;i<n;i++){
if(count==0){
if(A[i]==0){res++;count=1;}
}
else{
if(A[i]==1){res++;count=0;}
}
}
return res;
}
