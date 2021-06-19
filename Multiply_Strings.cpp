// https://www.interviewbit.com/old/problems/multiply-strings/
/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

 Note: The numbers can be arbitrarily large and are non-negative.
Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer. 
For example,
given strings "12", "10", your answer should be “120”.

NOTE : DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ).
We will retroactively disqualify such submissions and the submissions will incur penalties.
*/

string Solution::multiply(string A, string B) {
    int n = A.length(),m = B.length();
string res(n+m,'0');

for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
        int num = (A[i] - '0') * (B[j] - '0') + res[i+j+1] - '0';
        res[i+j+1] = num%10 + '0';
        res[i+j]+= num/10;
    }
}
for(int i=0;i<res.length();i++) if(res[i] != '0') return res.substr(i);
return "0";
}
