//https://www.interviewbit.com/problems/highest-product/
/*
Given an array A, of N integers A.

Return the highest product possible by multiplying 3 numbers from the array.

NOTE:  Solution will fit in a 32-bit signed integer.
*/
int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    if(n < 3) {
        return 0;
    }
    sort(A.begin(), A.end());
    return max(A[0]*A[1]*A[n-1]      , A[n-1]* A[n-2]*A[n-3]);
}
