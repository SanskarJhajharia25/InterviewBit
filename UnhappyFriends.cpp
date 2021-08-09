/*
https://leetcode.com/problems/count-unhappy-friends/submissions/

You are given a list of preferences for n friends, where n is always even.

For each person i, preferences[i] contains a list of friends sorted in the order of preference. In other words, a friend earlier in the list is more preferred than a friend later in the list. Friends in each list are denoted by integers from 0 to n-1.

All the friends are divided into pairs. The pairings are given in a list pairs, where pairs[i] = [xi, yi] denotes xi is paired with yi and yi is paired with xi.

However, this pairing may cause some of the friends to be unhappy. A friend x is unhappy if x is paired with y and there exists a friend u who is paired with v but:

x prefers u over y, and
u prefers x over v.
Return the number of unhappy friends.
*/

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
         unordered_map<int, unordered_set<int>> morePreferred;
        
        //Adding all friends a person prefers more than their pair
        for(int i=0; i<pairs.size(); i++)
        {
            int first = pairs[i][0], second = pairs[i][1];
            
            //adding all friends that occur before alloted pair in preference list
            for(int j=0; j<preferences[first].size(); j++)
            {
                if(preferences[first][j] == second)
                    break;
                morePreferred[first].insert(preferences[first][j]);
            }
            
            for(int j=0; j<preferences[second].size(); j++)
            {
                if(preferences[second][j] == first)
                    break;
                morePreferred[second].insert(preferences[second][j]);
            }
        }
        
        int unhappy = 0;
        
        for(auto it = morePreferred.begin(); it != morePreferred.end(); it++)
        {
            unordered_set<int> morePref = it->second;
            
            //traversing all more preffered friends for a person
            for(auto it1 = morePref.begin(); it1 != morePref.end(); it1++)
            {
                //cout<<*it1<<endl;
                if(morePreferred.find(*it1) == morePreferred.end())
                    continue;
                //if their more preferred person also prefers them more than their partner
                if(morePreferred[*it1].find(it->first) != morePreferred[*it1].end())
                {
                    unhappy++;
                    break; // count unhappy person only once
                }
            }
        }
        
        return unhappy;
    }
};
