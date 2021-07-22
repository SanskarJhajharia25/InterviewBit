/*

https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> a;
vector<int> hash(26, 0);
vector<int> phase(26, 0);

    int window = p.size();
    int leng = s.size();

    if (leng < window)
    {
        return a;
    }
    int left = 0, right = 0;
    while(right<window)
    {
        phase[p[right] - 'a'] += 1;
        hash[s[right++] - 'a'] += 1;
    }
    right -= 1;

    while(right<leng)
    {
        if (phase == hash)
        {
            a.push_back(left);
        }
        right += 1;
        if (right != leng)
        {
           hash[s[right] -'a'] += 1;
        }
        hash[s[left] -'a'] -= 1;
        left +=1;
    }
    return a;
    }
};
