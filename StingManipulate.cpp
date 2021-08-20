/*
https://leetcode.com/problems/string-without-aaa-or-bbb/

Given two integers a and b, return any string s such that:

s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
The substring 'aaa' does not occur in s, and
The substring 'bbb' does not occur in s.

*/

class Solution {
public:
    string strWithout3a3b(int a, int b) {
         int size=a+b;
        string res="";
        while(a||b){
            if(a>b){
               res+="aab"; 
                a-=2;
                b-=1;
                a=max(0,a);
                b=max(0,b);
            }
            else if(b>a){
               res+="bba"; 
                a-=1;
                b-=2;
                a=max(0,a);
                b=max(0,b);
            } 
            else{
               res+="ab";
                b-=1;
                a-=1;
                b=max(0,b);
                a=max(0,a);
            }
        }
        return res.substr(0,size);
    }
};
