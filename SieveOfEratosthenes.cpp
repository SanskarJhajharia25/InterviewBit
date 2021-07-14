/*
https://leetcode.com/problems/count-primes/submissions/

Count the number of prime numbers less than a non-negative number, n.
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isPrime(n+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2;i*i<=n;i++)
        {
            if(isPrime[i])
            {    
                for(int j=2*i;j<=n;j=j+i)
                {
                    isPrime[j]=false;
                }
            }    
        }
        int res =0;
        for(int i =0;i<n;i++)
        {
            if(isPrime[i])
            {
                res++;
            }
        }
        return res;
    }
};
