/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/
class Solution {
public:
    string arr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void lc(string digits,string x,int i)
    {
        if(i==digits.length())
        {
            ans.push_back(x);
            return;
        }
        for(int j=0;j<arr[digits[i]-'0'].length();j++)
        {
            string temp=x;
            temp=temp+arr[digits[i]-'0'][j];
            lc(digits,temp,i+1);
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) 
    {
        if(digits.length()==0)
            return ans;
        lc(digits,"",0);
        return ans;
        
    }
};
