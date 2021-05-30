//Given a Linked List A consisting of N nodes. The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's. You need to sort the linked list and return the new linked list.
// 1 -> 0 -> 0 -> 1    output:  0 -> 0 -> 1 -> 1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) 
{
    int z=0,o=0; //To count the number of ones and zeroes 
    ListNode* temp=A;
    ListNode* temp2=A;
    while(temp!=NULL)
    {
        if(temp->val==0)
           z++;
        else 
          o++;
        temp=temp->next;
    }
    while(A!=NULL)
    {
      if(z>0)
      {
        A->val=0;
        z--;
      }
      else
      {
          A->val=1;
      }
      A=A->next;
     }
     return temp2;
}
