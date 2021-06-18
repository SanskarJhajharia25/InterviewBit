//https://www.interviewbit.com/problems/flip/
/*
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.
*/


vector<int> Solution::flip(string A) {
    int n = A.size();

int l =0 , r =0 ;
int s = 0;
int L,R;
int ans = INT_MIN;

 vector<int>res;
 int c =0 ;
 for( int i = 0 ; i< n ;i++ )
    { 
        if( A[i] == '1' ) 
        c++;  
    }

 if( c == n )return res;

for( int i = 0  ; i<n ; i++ )
{
    
    if( A[i] == '0' ){ s++; r = i ;}
    
    else if ( A[i] == '1' )
    {
        s-- ; 
    
        if( s < 0 ) { s = 0;  l = i+1 ; r = i+1 ; }
    }
    
    if( s > ans )
    {
        ans = s ;
        L = l ; R = r ;
    }
}

// cout<<ans<<endl;


res.push_back(L+1);
res.push_back(R+1);

return res;
}
