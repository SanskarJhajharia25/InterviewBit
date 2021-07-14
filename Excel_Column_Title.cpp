/*

https://www.interviewbit.com/problems/excel-column-title/

Given a positive integer A, return its corresponding column title as appear in an Excel sheet.
*/

string Solution::convertToTitle(int A) {
    string w="";
    while(A!=0)
    {
        int r=A%26;
        A/=26;
        if(r==0)
        {
            w = 'Z'+w;
            A=A-1;
            continue;
        }
        char c=(char)(r+'A'-1);
        w = c+w;
    }
    return w;
}

