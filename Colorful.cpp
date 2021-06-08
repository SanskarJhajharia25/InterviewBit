/*For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequen*/

int Solution::colorful(int A) 
{
    unordered_map<int, bool>m; //Taking a map with int and boolean value
    while(A) 
    {
        int p=1, curr= A;
        while(curr) 
        {
            p = p*(curr%10); //starting from right side, we take all subsequneces possible and p stores their sum
            if(m.find(p) != m.end())return 0; //if the provided product already exists
            m[p] = true; //Re structure
            curr /= 10;
        }
        A /= 10;
    }
    return 1;
}
