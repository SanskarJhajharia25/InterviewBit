/*
https://leetcode.com/problems/custom-sort-string/submissions/
You are given two strings order and s. All the words of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.
*/

class Solution {
public:
    string customSortString(string order, string s) {
        string unorder = "";
        map<char, int> m;
        for(int i=0; i<order.size(); i++){
            m[order[i]] = i;
        }
        vector<pair<char,int>> vec(26, {'_',0});
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i]) != m.end()){
                vec[m[s[i]]].first = s[i];
                vec[m[s[i]]].second++; 
            }
            else{
                unorder+= s[i];
            }
        }
        string ans="";
        for(int i=0; i<vec.size(); i++){
            if(vec[i].first >= 'a' && vec[i].first <= 'z'){
                int append = vec[i].second;
                while(append!=0) {
                    ans+= vec[i].first;
                    append--;
                }
            }
        }
        ans+= unorder;
        return ans;
    }
};
