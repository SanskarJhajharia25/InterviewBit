/*

https://leetcode.com/problems/merge-k-sorted-lists/submissions/
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

*/

/* Approach:
In a multiset STL, the data is already sorted. SO use that */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& A) {
        multiset<pair<int,ListNode*>> st;
        
        for(auto thead:A)
        {
            ListNode *cur = thead;
            while(cur)
            {
                st.insert({cur->val, cur});
                cur=cur->next;
            }
        }
        
        ListNode *head=NULL, *tail = NULL;
        
        while(st.size()>0)
        {
            pair<int, ListNode*> temp = *st.begin();
            
            st.erase(st.begin());
            
            if(head==NULL)
                head = temp.second,
                tail = temp.second;
            else
                tail->next = temp.second,
                tail = temp.second;
        }
        
        return head;
    }
};
