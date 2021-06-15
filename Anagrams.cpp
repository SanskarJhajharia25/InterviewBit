/*
Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

 Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp' 
 Note: All inputs will be in lower-case. 
Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4.
dog and god are another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element has index 1 instead of index 0).

 Ordering of the result : You should not change the relative ordering of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before A[j] if i < j.
 */
 
 vector<vector<int> > Solution::anagrams(const vector<string> &s) {
    vector<string> strs=s;
    map<string,vector<int>> mp;
    vector<vector<int>> v1;
        
    for(int i=0;i<strs.size();i++)
    {
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(i+1);
    }
    for(auto it: mp)
    {
           vector<int> v;
            for(auto it1: mp[it.first])
            {
              v.push_back(it1);
            }
           v1.push_back(v);
    }
       
    return v1;
}
