// https://www.interviewbit.com/problems/magician-and-chocolates/
/*

Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.

Find the maximum number of chocolates that kid can eat in A units of time.

*/

int Solution::nchoc(int A, vector<int> &B) 
{

    priority_queue<int> pq;
    for(int i=0;i<B.size();i++)
      pq.push(B[i]);

    long long sum=0;
    while(A)
    {
      int num=pq.top();
      sum += num;
      pq.pop();
      pq.push(floor(num/2));
      A--;
    }
    return sum%(1000000007);
}

