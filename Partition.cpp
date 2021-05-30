/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int length(ListNode* A)
{//Returns the number of elements in the list
  int count=0;
  ListNode* ptr=A;

  while(ptr!=NULL)
  {
    count++;
    ptr=ptr->next;
  }
  return count;
}

ListNode* Solution::partition(ListNode* A, int B) 
{
  ListNode front(0),end(0);
  ListNode* f= &front;
  ListNode* e = &end;
  int n = length(A);
  for(int i=0;i<n;i++)
  {
    if(A->val < B)
    {
      f->next = A;
      f = f->next;
    }
    else
    {
      e->next=A;  
      e = e->next;
    }
    A=A->next;
  }
   f->next = end.next;
   e->next=NULL;
   return front.next;
}
