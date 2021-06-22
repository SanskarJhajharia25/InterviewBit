//https://www.interviewbit.com/problems/merge-k-sorted-lists/

//Merge k sorted linked lists and return it as one sorted list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

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
