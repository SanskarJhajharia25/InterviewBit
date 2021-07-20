/*
https://www.interviewbit.com/old/problems/compare-version-numbers/
Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:
*/

int Solution::compareVersion(string A, string B) {
     int i = 0, j = 0, len1 = A.size(), len2 = B.size();
    while( i<len1 || j<len2 ) {
        unsigned long num1 = 0, num2 = 0;
        while(i<len1 && A[i] != '.')
            num1 = num1*10+(A[i++]-'0');
        while(j<len2 && B[j] != '.')
            num2 = num2*10+(B[j++]-'0');
        if(num1 != num2)    return num1 < num2 ? -1 : 1;
        i++, j++;
    }
    return 0;
}
